/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-
   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2003 Koblenz University
   $Id: agentframe.cpp,v 1.1 2008/02/24 16:20:21 rollmark Exp $

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
// -*- C++ -*- generated by wxGlade 0.4.1 on Fri Feb 23 21:06:30 2007
#include "agentframe.h"
#include "constants.h"
#include <wx/filename.h>

#include <rsgedit/res/xpm_play.xpm>
#include <rsgedit/res/xpm_stop.xpm>

//! wxWidgets and zeitgeist both use a 'DECLARE_CLASS' macro
#undef DECLARE_CLASS

BEGIN_EVENT_TABLE(agentframe, wxFrame)
    EVT_TIMER(1, agentframe::OnLogTimer)
    EVT_CLOSE(agentframe::OnClose)
    EVT_END_PROCESS(1, agentframe::OnEndProcess)

    EVT_UPDATE_UI(ID_AGENT_START, agentframe::OnUpdateAgentStart)
    EVT_MENU(ID_AGENT_START, agentframe::OnAgentStart)

    EVT_UPDATE_UI(ID_AGENT_KILL, agentframe::OnUpdateAgentKill)
    EVT_MENU(ID_AGENT_KILL, agentframe::OnAgentKill)

END_EVENT_TABLE()

agentframe::agentframe(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxCAPTION|wxCLOSE_BOX|wxSYSTEM_MENU|wxRESIZE_BORDER|wxFRAME_TOOL_WINDOW|wxFRAME_NO_TASKBAR|wxFRAME_FLOAT_ON_PARENT|wxCLIP_CHILDREN),
    mTimer(this,1),mProcess(0),mPid(0)
{
    mToolBar = 0;

    // begin wxGlade: agentframe::agentframe
    mCtrLog = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY);

    set_properties();
    do_layout();
    // end wxGlade

    // create toolbar
    mToolBar = CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL, wxID_ANY );
    mToolBar->AddTool(ID_AGENT_START, wxT("Start"), wxBitmap(xpm_play));
    mToolBar->AddTool(ID_AGENT_KILL, wxT("Kill"), wxBitmap(xpm_stop));

    mToolBar->Realize();
    SetToolBar(mToolBar);
}

agentframe::~agentframe()
{
    KillAgent();
}

void agentframe::set_properties()
{
    // begin wxGlade: agentframe::set_properties
    SetTitle(wxT("frame_1"));
    SetSize(wxSize(500, 200));
    // end wxGlade
}

void agentframe::do_layout()
{
    // begin wxGlade: agentframe::do_layout
    wxBoxSizer* sizer_10 = new wxBoxSizer(wxVERTICAL);
    sizer_10->Add(mCtrLog, 1, wxEXPAND, 0);
    SetSizer(sizer_10);
    Layout();
    // end wxGlade
}

void agentframe::Output(const wxString& str)
{
    mCtrLog->AppendText(str);
}

void 
agentframe::Output(const char* str)
{
    mCtrLog->AppendText((const wxChar *) str);
}

void agentframe::Output(wxInputStream* istream)
{
    if (istream == 0)
        {
            return;
        }

    while (istream->CanRead())
        {
            static wxChar buffer[4096];
            buffer[istream->Read(buffer, WXSIZEOF(buffer) - 1).LastRead()] = _T('\0');
            Output(buffer);
        }
}

void agentframe::KillAgent()
{
    if (mProcess == 0)
        {
            return;
        }

    Output("(agentframe::KillAgent) killing agent\n");

    mProcess->Detach();
    wxKillError error = wxProcess::Kill(mPid,wxSIGKILL);

    switch (error)
        {
        case wxKILL_OK:
            break;

        case wxKILL_BAD_SIGNAL:
            Output("(agentframe::KillAgent) no such signal");
            break;

        case wxKILL_ACCESS_DENIED:
            Output("(agentframe::KillAgent) permission denied");
            break;

        case wxKILL_NO_PROCESS:
            Output("(agentframe::KillAgent) no such process");
            break;

        case wxKILL_ERROR:
            Output("(agentframe::KillAgent) error killing process");
            break;
        }

    mProcess = 0;
    mPid = 0;
    mTimer.Stop();
    UpdateWindowUI(wxUPDATE_UI_RECURSE);
}

bool agentframe::StartAgent()
{
    Output((const wxChar*)("(agentframe::StartAgent) starting agent '") + mCmd + (const wxChar*)("'\n"));

    mProcess = new wxProcess(this, 1);
    mProcess->Redirect();

#ifdef WIN32
    // make sure that the working directory is set to the directory where
    // the executable is
    wxString cwd = wxGetCwd();
    wxSetWorkingDirectory(wxFileName(mCmd).GetPath());
#endif

    mPid = wxExecute(mCmd, wxEXEC_ASYNC, mProcess);

#ifdef WIN32
    // restore working directory
    wxSetWorkingDirectory(cwd);
#endif

    if (mPid == 0)
        {
            Output((const wxChar*)("(agentframe::StartAgent) failed to start '")+ mCmd+ (const wxChar*)("' \n"));
            mProcess = 0;
            return false;
        }

    mTimer.Start(LOGWND_UPDATE_INTERVAL);
    UpdateWindowUI(wxUPDATE_UI_RECURSE);
    return true;
}

bool agentframe::StartAgent(const wxString& cmd)
{
    KillAgent();

    mCmd = cmd;
    return StartAgent();
}

void agentframe::OnLogTimer(wxTimerEvent& event)
{
    if (mProcess == 0)
        {
            return;
        }

    wxInputStream* procIStream = mProcess->GetInputStream();
    if (procIStream != 0)
        {
            Output(procIStream);
        }

    wxInputStream* procEStream = mProcess->GetErrorStream();
    if (procEStream != 0)
    {
        Output(procEStream);
    }
}

void agentframe::OnClose(wxCloseEvent& event)
{
    KillAgent();
    event.Skip();
}

void agentframe::OnEndProcess(wxProcessEvent& event)
{
    Output("(agentframe::OnEndProcess) agent died");
    mTimer.Stop();
    mProcess->Detach();
    mProcess = 0;
}

void agentframe::OnUpdateAgentStart(wxUpdateUIEvent& event)
{
    event.Enable(mProcess == 0);
}

void agentframe::OnAgentStart(wxCommandEvent& /*event*/)
{
    StartAgent();
}

void agentframe::OnUpdateAgentKill(wxUpdateUIEvent& event)
{
    event.Enable(mProcess != 0);
}

void agentframe::OnAgentKill(wxCommandEvent& /*event*/)
{
    KillAgent();
}
