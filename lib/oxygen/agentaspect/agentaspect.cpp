/* -*- mode: c++; c-basic-indent: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2002,2003 Koblenz University
   Copyright (C) 2003 RoboCup Soccer Server 3D Maintenance Group
   $Id: agentaspect.cpp,v 1.4 2003/12/21 23:36:36 fruit Exp $

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
#include "agentaspect.h"
#include "createeffector.h"
#include <zeitgeist/logserver/logserver.h>

using namespace boost;
using namespace oxygen;
using namespace salt;
using namespace std;

bool
AgentAspect::RealizeActions(boost::shared_ptr<ActionObject::TList> actions)
{
  UpdateEffectorMap();

  for (
       ActionObject::TList::iterator iter = actions->begin();
       iter != actions->end();
       ++iter
       )
    {
      shared_ptr<ActionObject> action = (*iter);
      std::string predicate = action->GetPredicate();

      shared_ptr<Effector> effector = GetEffector(predicate);
      if (effector.get() == 0)
        {
          GetLog()->Warning()
            <<  "(AgentAspect) No effector found for predicate "
            << predicate << "\n";
          continue;
        }

      bool realized = effector->Realize(action);

      if (! realized)
        {
          GetLog()->Warning()
            << "(AgentAspect) Failed to realize predicate "
            << predicate << "\n";
        }
    }

  return true;
}

shared_ptr<BaseParser::TPredicateList>
AgentAspect::QueryPerceptors()
{
  // build list of perceptors, searching recursively
  TLeafList perceptors;
  GetChildrenSupportingClass("Perceptor",perceptors,true);

  shared_ptr<BaseParser::TPredicateList>
    predList(new BaseParser::TPredicateList());

  // query the perceptors for new data
  for (
       TLeafList::iterator iter = perceptors.begin();
       iter != perceptors.end();
       ++iter
       )
    {
      shared_ptr<Perceptor> perceptor
        = shared_dynamic_cast<Perceptor>(*iter);

      if (perceptor.get() == 0)
        {
          continue;
        }

      BaseParser::TPredicate predicate;
      bool hasData = perceptor->Percept(predicate);

      if (hasData)
        {
          predList->push_back(predicate);
        }
    }

  return predList;
}

shared_ptr<Effector>
AgentAspect::GetEffector(const std::string predicate) const
{
  TEffectorMap::const_iterator iter = mEffectorMap.find(predicate);

  if (iter == mEffectorMap.end())
    {
      return shared_ptr<Effector>();
    }

  return (*iter).second;
}

void
AgentAspect::UpdateEffectorMap()
{
  // build list of effectors, searching recursively
  TLeafList effectors;
  GetChildrenSupportingClass("Effector",effectors,true);

  // build the effector map
  mEffectorMap.clear();

  for (
       TLeafList::iterator iter = effectors.begin();
       iter != effectors.end();
       ++iter
       )
    {
      shared_ptr<Effector> effector
        = shared_dynamic_cast<Effector>(*iter);

      if (effector.get() == 0)
        {
          continue;
        }

      mEffectorMap[effector->GetPredicate()] = effector;
    }
}

bool AgentAspect::Init()
{
  shared_ptr<CreateEffector> create = shared_dynamic_cast<CreateEffector>
    (GetCore()->New("kerosin/CreateEffector"));

  if (create.get() == 0)
    {
      GetLog()->Error()
        << "ERROR: (AgentAspect) Could not construct a CreateEffector\n";
      return false;
    }

  create->SetName("_CreateEffector");

  // link it into our hierarchy
  bool added = AddChildReference(create);

  if (! added)
    {
      GetLog()->Error()
        << "ERROR: (AgentAspect) failed to set up the CreateEffectorn";
      return false;
    } else
      {
        GetLog()->Debug() << "(AgentAspect) created CreateEffector\n";
      }

  return added;
}
