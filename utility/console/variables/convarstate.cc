/* -*- mode: c++ -*-
   
   this file is part of Soccer Server 3D
   Copyright (C) 2002 Soccer Server Maintainance Group

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
  
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#include <sstream>
#include <iomanip>

#include "convarstate.h"

using namespace std;

ConVarState::ConVarState()
{
    M_attributes = ConVarAttributes::getDefault();
}

ConVarState::ConVarState(const ConVarAttributes& attributes) : 
    M_attributes(attributes)
{
}

ConVarState::~ConVarState()
{
}

bool 
ConVarState::isOfType(ConVar::ConVarType type) const
{
    return getType() == type;
}

bool 
ConVarState::setBool(bool value)
{
    return false;
}

bool 
ConVarState::setInt(int value)
{
    return false;
}

bool 
ConVarState::setFloat(TFloat value)
{
    return false;
}

bool 
ConVarState::setString(const std::string& value)
{
    return false;
}

bool 
ConVarState::setCharString(const char* value)
{
    return false;
}

bool 
ConVarState::setVector(const Vector3& value)
{
    return false;
}

bool 
ConVarState::setCommand(const ConCommand* value)
{
    return false;
}

bool 
ConVarState::setVariable(ConVar* value)
{
    return false;
}

bool 
ConVarState::setLabel(const std::string& value)
{
    return false;
}

bool 
ConVarState::getBool(bool& value) const
{
    return false;
}

bool 
ConVarState::getInt(int& value) const
{
    return false;
}

bool 
ConVarState::getFloat(TFloat& value) const
{
    return false;
}

bool 
ConVarState::getString(string& value) const
{
    return false;
}

bool 
ConVarState::getCharString(char** value) const
{
    return false;
}

bool 
ConVarState::getVariable(ConVar** value) const
{
    return false;
}

bool 
ConVarState::getCommand(const ConCommand** value) const
{
    return false;
}

bool
ConVarState::getVector(Vector3& value) const
{
    return false;
}

bool 
ConVarState::getLabel(std::string& value) const
{
    return false;
}

ConVarAttributes 
ConVarState::getAttributes() const
{
    return M_attributes;
}

void
ConVarState::setAttributes(const ConVarAttributes& attributes)
{
    M_attributes = attributes;
}

string 
ConVarState::dump() const
{
    stringstream ss;

    ss << setw(30) << getAttributes().getName() << " " << dumpValue() << endl;
    return ss.str();
}

string 
ConVarState::dumpWithSignature() const
{
    stringstream ss;

    ss << setw(5) << getAttributes().dumpRemovable()
       << setw(6) << getAttributes().dumpConstant()
       << setw(14) << dumpType()
       << setw(25) << getAttributes().dumpGroup() << dump();

    return ss.str();
}
