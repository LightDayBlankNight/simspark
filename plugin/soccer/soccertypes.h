/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2002,2003 Koblenz University
   Copyright (C) 2003 RoboCup Soccer Server 3D Maintenance Group
   $Id: soccertypes.h,v 1.5 2004/05/05 14:00:25 fruit Exp $

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
#ifndef SOCCERTYPES_H
#define SOCCERTYPES_H

/** this file contains types common to all plugins in the soccer
    simulation
*/

#include <string>

enum TPlayMode
{
    PM_BeforeKickOff,
    PM_KickOff_Left,
    PM_KickOff_Right,
    PM_KickOff,                /*!< kick_off:          no real play mode. kick off for a random team */
    PM_PlayOn,
    PM_KickIn_Left,
    PM_KickIn_Right,
    PM_CORNER_KICK_LEFT,       /*!< corner_kick_l:     corner kick left team   */
    PM_CORNER_KICK_RIGHT,      /*!< corner_kick_r:     corner kick right team  */
    PM_GOAL_KICK_LEFT,         /*!< goal_kick_l:       goal kick for left team */
    PM_GOAL_KICK_RIGHT,        /*!< goal_kick_r:       goal kick for right team*/
    PM_OFFSIDE_LEFT,           /*!< offside_l:         offside for left team   */
    PM_OFFSIDE_RIGHT,          /*!< offside_r:         offside for right team  */
    PM_GameOver,
    PM_Goal_Left,
    PM_Goal_Right,
    PM_FREE_KICK_LEFT,         /*!< free_kick_l:       free kick for left team */
    PM_FREE_KICK_RIGHT,        /*!< free_kick_r:       free kick for right team*/
    PM_NONE
};

/** mapping from TPlayMode to string constants */
#define STR_PM_BeforeKickOff "BeforeKickOff"
#define STR_PM_KickOff_Left "KickOff_Left"
#define STR_PM_KickOff_Right "KickOff_Right"
#define STR_PM_KickOff "KickOff"
#define STR_PM_PlayOn "PlayOn"
#define STR_PM_KickIn_Left "KickIn_Left"
#define STR_PM_KickIn_Right "KickIn_Right"
#define STR_PM_CORNER_KICK_LEFT "corner_kick_left"
#define STR_PM_CORNER_KICK_RIGHT "corner_kick_right"
#define STR_PM_GOAL_KICK_LEFT "goal_kick_left"
#define STR_PM_GOAL_KICK_RIGHT "goal_kick_right"
#define STR_PM_OFFSIDE_LEFT "offside_left"
#define STR_PM_OFFSIDE_RIGHT "offside_right"
#define STR_PM_GameOver "GameOver"
#define STR_PM_Goal_Left "Goal_Left"
#define STR_PM_Goal_Right "Goal_Right"
#define STR_PM_FREE_KICK_LEFT "free_kick_left"
#define STR_PM_FREE_KICK_RIGHT "free_kick_right"
#define STR_PM_Unknown "unknown"

enum TTeamIndex
{
    TI_NONE = 0,
    TI_LEFT = 1,
    TI_RIGHT = 2
};

typedef float TTime;

enum TGameHalf
{
    GH_NONE = 0,
    GH_FIRST = 1,
    GH_SECOND = 2
};

#endif // SOCCERTYPES_H
