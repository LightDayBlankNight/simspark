/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-
   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2003 Koblenz University
   $Id: agentcontrol.h,v 1.1 2004/04/25 16:46:57 rollmark Exp $

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
#ifndef OXYGEN_AGENTCONTROL_H
#define OXYGEN_AGENTCONTROL_H

#include "netcontrol.h"

namespace oxygen
{
class GameControlServer;

/** \class AgentControl is a NetControl node that manages the
    communication with agents in cooperation with the
    GameControlServer.
 */

class AgentControl : public NetControl
{
public:
    AgentControl();
    virtual ~AgentControl();

    /** called when a new client connects */
    virtual void ClientConnect(boost::shared_ptr<Client> client);

    /** called when a client disconnects */
    virtual void ClientDisconnect(boost::shared_ptr<Client> client);

protected:
    virtual void OnLink();
    virtual void OnUnlink();

protected:
    /** cached reference to the GameControlServer */
    boost::shared_ptr<GameControlServer> mGameControlServer;
};

DECLARE_CLASS(AgentControl);

} // namespace oxygen

#endif // OXYGEN_AGENTCONTROL_H
