/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Copyright (C) 2002,2003 Koblenz University
   Copyright (C) 2003 RoboCup Soccer Server 3D Maintenance Group
   $Id: basenode.cpp,v 1.6.2.1 2004/03/27 12:59:57 rollmark Exp $

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

   BaseNode
*/

#include "basenode.h"
#include "scene.h"

using namespace boost;
using namespace oxygen;
using namespace salt;
using namespace zeitgeist;

const salt::Matrix BaseNode::mIdentityMatrix(salt::Matrix::GetIdentity());

BaseNode::BaseNode() :
    zeitgeist::Node(), mDebugMode(false)
{
}

BaseNode::~BaseNode()
{
}

const salt::Matrix& BaseNode::GetLocalTransform() const
{
    return mIdentityMatrix;
}

const salt::Matrix& BaseNode::GetWorldTransform() const
{
    shared_ptr<BaseNode> parent = shared_static_cast<BaseNode>
        (make_shared(mParent));

    // no parent, return identity
    if (parent.get() == 0)
        {
            return mIdentityMatrix;
        } else
            {
                return parent->GetWorldTransform();
            }
}

void BaseNode::SetLocalTransform(const salt::Matrix& /*transform*/)
{
}

void BaseNode::SetWorldTransform(const salt::Matrix& /*transform*/)
{
}

// This routine is responsible for updating the local bounding box of
// the node. The default behavior is to treat the node as a point.
// Note that this is always called from Compute().
void BaseNode::ComputeBoundingBox()
{
    mLocalBoundingBox.minVec.Set(0,0,0);
    mLocalBoundingBox.maxVec.Set(0,0,0);
}

void BaseNode::PrePhysicsUpdate(float deltaTime)
{
    // perform update on hierarchy
    TLeafList baseNodes;
    ListChildrenSupportingClass<BaseNode>(baseNodes);
    for (TLeafList::iterator i = baseNodes.begin(); i!= baseNodes.end(); ++i)
        {
            shared_static_cast<BaseNode>(*i)->PrePhysicsUpdate(deltaTime);
        }

    // do the internal update. This can be overridden by derived classes
    // to add custom behavior
    PrePhysicsUpdateInternal(deltaTime);

    ComputeBoundingBox();
}

void BaseNode::PostPhysicsUpdate()
{
    // perform update on hierarchy
    TLeafList baseNodes;
    ListChildrenSupportingClass<BaseNode>(baseNodes);
    for (TLeafList::iterator i = baseNodes.begin(); i!= baseNodes.end(); ++i)
        {
            shared_static_cast<BaseNode>(*i)->PostPhysicsUpdate();
        }

    // do the internal update this can be overridden by derived classes
    // to add custom behavior
    PostPhysicsUpdateInternal();
}

void BaseNode::UpdateHierarchy()
{
    // do the internal update this can be overridden by derived classes
    // to add custom behavior
    UpdateHierarchyInternal();

    // generate the bounding volume of this node
    Matrix worldTransform = GetWorldTransform();
    mWorldBoundingBox = mLocalBoundingBox;
    mWorldBoundingBox.TransformBy(worldTransform);

    // perform update on hierarchy
    TLeafList baseNodes;
    ListChildrenSupportingClass<BaseNode>(baseNodes);
    for (TLeafList::iterator i = baseNodes.begin(); i!= baseNodes.end(); ++i)
        {
            shared_ptr<BaseNode> node = shared_static_cast<BaseNode>(*i);
            node->UpdateHierarchy();

            // here we merge our world bounding volume with the child
            // volumes
            mWorldBoundingBox.Encapsulate(node->GetWorldBoundingBox());
        }
}

shared_ptr<Scene> BaseNode::GetScene()
{
    return make_shared(FindParentSupportingClass<Scene>());
}

void BaseNode::EnableDebugMode()
{
    mDebugMode = true;
}

void BaseNode::DisableDebugMode()
{
    mDebugMode = false;
}

void BaseNode::PrePhysicsUpdateInternal(float /*deltaTime*/)
{
}

void BaseNode::PostPhysicsUpdateInternal()
{
}

void BaseNode::UpdateHierarchyInternal()
{
}

void BaseNode::RenderInternal()
{
}

void BaseNode::RenderAmbientInternal()
{
}

const salt::AABB3& BaseNode::GetWorldBoundingBox() const
{
    return mWorldBoundingBox;
}

