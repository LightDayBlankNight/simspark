/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2002,2003 Koblenz University
   Copyright (C) 2003 RoboCup Soccer Server 3D Maintenance Group
   $Id: sparkmonitor.cpp,v 1.1 2004/04/28 14:52:57 rollmark Exp $

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
#include "sparkmonitor.h"
#include <zeitgeist/logserver/logserver.h>
#include <kerosin/sceneserver/singlematnode.h>
#include <kerosin/materialserver/material.h>
#include <sstream>

using namespace kerosin;
using namespace oxygen;
using namespace boost;
using namespace salt;
using namespace std;

SparkMonitor::SparkMonitor() : oxygen::MonitorSystem()
{
}

SparkMonitor::~SparkMonitor()
{
}

void SparkMonitor::OnLink()
{
    // setup SceneServer reference
    mSceneServer = shared_dynamic_cast<SceneServer>
        (GetCore()->Get("/sys/server/scene"));

    if (mSceneServer.get() == 0)
        {
            GetLog()->Error()
                << "(SparkMonitor) ERROR: SceneServer not found\n";
        }
}

void SparkMonitor::OnUnlink()
{
    mSceneServer.reset();
    mActiveScene.reset();
}

void SparkMonitor::ParseMonitorMessage(const std::string& data)
{
}

string SparkMonitor::GetMonitorInfo()
{
    if (mSceneServer.get() == 0)
        {
            return "";
        }

    mActiveScene = mSceneServer->GetActiveScene();

    stringstream ss;
    ss << "(RubySceneGraph 0 1)";

    if (mActiveScene.get() != 0)
        {
            DescribeScene(ss,mActiveScene);
        }

    ss << endl;

    return ss.str();
}

string SparkMonitor::GetMonitorHeaderInfo()
{
    return "(header)";
}

void SparkMonitor::DescribeLight(stringstream& ss, shared_ptr<Light> light)
{
    ss << "(node Light ";

    const RGBA& diff = light->GetDiffuse();
    ss << "(setDiffuse " << diff.r() << " " << diff.g() << " "
       << diff.b() << " " << diff.a() << ") ";

    const RGBA& amb = light->GetAmbient();
    ss << "(setAmbient " << amb.r() << " " << amb.g() << " "
       << amb.b() << " " << amb.a() << ") ";

    const RGBA& spec = light->GetSpecular();
    ss << "(setSpecular " << spec.r() << " " << spec.g() << " "
       << spec.b() << " " << spec.a() << ")";
}

void SparkMonitor::DescribeTransform(stringstream& ss, shared_ptr<Transform> transform)
{
    const Matrix& mat = transform->GetLocalTransform();

    ss << "(node Transform (setLocalTransform ";

    for (int i=0;i<16;++i)
        {
            ss << mat.m[i] << " ";
        }

    ss << ")";
}

void SparkMonitor::DescribeMesh(stringstream& ss, boost::shared_ptr<StaticMesh> mesh)
{
    shared_ptr<SingleMatNode> singleMat =
        shared_dynamic_cast<SingleMatNode>(mesh);

    if (singleMat.get() != 0)
        {
            ss << "(node SingleMatNode";
        } else
            {
                ss << "(node StaticMesh";
            }

    const shared_ptr<TriMesh> triMesh = mesh->GetMesh();
    if (triMesh.get() != 0)
        {
            // mangled CCylinder ??
            ss << " (load " << triMesh->GetName() << ")";

            const Vector3f& scale = mesh->GetScale();

            ss << " (setScale "
               << scale[0] << " "
               << scale[1] << " "
               << scale[2] << ")";

            if (singleMat.get() != 0)
                {
                    shared_ptr<Material> mat = singleMat->GetMaterial();
                    if (mat.get() != 0)
                        {
                            ss << " (setMaterial " << mat->GetName() << ")";
                        }
                }
        }

    ss << "";
}

void SparkMonitor::DescribeNode(stringstream& ss, shared_ptr<BaseNode> node)
{
    // Transform node
    shared_ptr<Transform> transform =
        shared_dynamic_cast<Transform>(node);

    if (transform.get() != 0)
        {
            DescribeTransform(ss,transform);
            return;
        }

    // StaticMesh node
    shared_ptr<StaticMesh> mesh =
        shared_dynamic_cast<StaticMesh>(node);

    if (mesh.get() != 0)
        {
            DescribeMesh(ss,mesh);
            return;
        }

    // Light node
    shared_ptr<Light> light =
        shared_dynamic_cast<Light>(node);

    if (light.get() != 0)
        {
            DescribeLight(ss,light);
            return;
        }

    // default to BaseNode
    ss << "(node BaseNode";
}

void SparkMonitor::DescribeScene(stringstream& ss, shared_ptr<BaseNode> node)
{
    DescribeNode(ss, node);

    for (TLeafList::iterator i = node->begin(); i!= node->end(); ++i)
        {
            shared_ptr<BaseNode> baseNode = shared_dynamic_cast<BaseNode>(*i);
            if (baseNode.get() == 0)
                {
                    continue;
                }

            DescribeScene(ss,baseNode);
        }

    ss << ")";
}
