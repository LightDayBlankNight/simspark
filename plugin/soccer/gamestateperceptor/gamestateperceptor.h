/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2002,2003 Koblenz University
   Copyright (C) 2003 RoboCup Soccer Server 3D Maintenance Group
   $Id: gamestateperceptor.h,v 1.1.2.1 2004/02/03 09:35:32 rollmark Exp $

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
#ifndef GAMESTATEPERCEPTOR_H
#define GAMESTATEPERCEPTOR_H

#include <oxygen/agentaspect/perceptor.h>
#include <soccer/soccertypes.h>

class GameStateAspect;

class GameStatePerceptor : public oxygen::Perceptor
{
public:
    GameStatePerceptor();
    virtual ~GameStatePerceptor();

    //! \return true, if valid data is available and false otherwise.
    virtual bool Percept(oxygen::Predicate& predicate);

protected:
    /** sets up the reference to the GameStateAspect */
    virtual void OnLink();

    /** resets the reference to the GameStateAspect */
    virtual void OnUnlink();

    /** returns a string describing the given playmode */
    std::string PlayMode2Str(const TPlayMode mode) const;

protected:
    //! a reference to the game state
    boost::shared_ptr<GameStateAspect> mGameState;
};

DECLARE_CLASS(GameStatePerceptor);

#endif // GAMESTATEPERCEPTOR_H
