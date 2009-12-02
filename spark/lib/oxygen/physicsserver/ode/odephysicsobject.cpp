/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2002,2003 Koblenz University
   Copyright (C) 2003 RoboCup Soccer Server 3D Maintenance Group
   $Id: odeobject.cpp 3 2008-11-21 02:38:08Z hedayat $

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
#include <oxygen/physicsserver/ode/odephysicsobject.h>
#include <oxygen/physicsserver/space.h>
#include <oxygen/physicsserver/world.h>
#include <oxygen/sceneserver/scene.h>
#include <iostream>

using namespace oxygen;
using namespace boost;
using namespace std;

ODEPhysicsObject::ODEPhysicsObject() : PhysicsObjectInt()
{
}

void ODEPhysicsObject::ConvertRotationMatrix(const salt::Matrix& rot, dMatrix3& matrix)
{
    matrix[0] = rot.m[0];
    matrix[1] = rot.m[4];
    matrix[2] = rot.m[8];
    matrix[3] = 0;
    matrix[4] = rot.m[1];
    matrix[5] = rot.m[5];
    matrix[6] = rot.m[9];
    matrix[7] = 0;
    matrix[8] = rot.m[2];
    matrix[9] = rot.m[6];
    matrix[10] = rot.m[10];
    matrix[11] = 0;
}

void ODEPhysicsObject::ConvertRotationMatrix(const dReal* matrix, salt::Matrix& rot) const
{
    rot.m[0] = matrix[0] ;
    rot.m[4] = matrix[1] ;
    rot.m[8] = matrix[2];
    rot.m[12] = matrix[3];
    rot.m[1] = matrix[4];
    rot.m[5] = matrix[5];
    rot.m[9] = matrix[6];
    rot.m[13] = matrix[7];
    rot.m[2] = matrix[8];
    rot.m[6] = matrix[9];
    rot.m[10] = matrix[10] ;
    rot.m[14] = matrix[11];
    rot.m[3] = 0.0;
    rot.m[7] = 0.0;
    rot.m[11] = 0.0;
    rot.m[15] = 1.0;
}