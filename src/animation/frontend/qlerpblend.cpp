/****************************************************************************
**
** Copyright (C) 2017 Klaralvdalens Datakonsult AB (KDAB).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qlerpblend.h"
#include "qlerpblend_p.h"
#include <Qt3DAnimation/qanimationclip.h>
#include <Qt3DAnimation/qclipblendnodecreatedchange.h>

QT_BEGIN_NAMESPACE

namespace Qt3DAnimation {

/*!
    \qmltype LerpBlend
    \instantiates Qt3DAnimation::QLerpBlend
    \inqmlmodule Qt3D.Animation

    \brief Performs a linear interpolation of two animation clips based on a
    normalized factor

    \since 5.9

    LerpBlend can be useful to create advanced animation effects based on
    individual animation clips. For instance, given a player character,, lerp
    blending could be used to combine a walking animation clip with an injured
    animation clip based on a blend factor that increases the more the player
    gets injured. This would then allow with blend factor == 0 to have a non
    injured walking player, with blend factor == 1 a fully injured player, with
    blend factor == 0.5 a partially walking and injured player.

    \sa BlendedClipAnimator
*/

/*!
    \class Qt3DAnimation::QLerpBlend
    \inmodule Qt3DAnimation
    \inherits Qt3DAnimation::QAbstractClipBlendNode

    \brief Performs a linear interpolation of two animation clips based on a
    normalized factor

    \since 5.9

    QLerpBlend can be useful to create advanced animation effects based on
    individual animation clips. For instance, given a player character,, lerp
    blending could be used to combine a walking animation clip with an injured
    animation clip based on a blend factor that increases the more the player
    gets injured. This would then allow with blend factor == 0 to have a non
    injured walking player, with blend factor == 1 a fully injured player, with
    blend factor == 0.5 a partially walking and injured player.

    \sa QBlendedClipAnimator
*/

QLerpBlendPrivate::QLerpBlendPrivate()
    : QAbstractClipBlendNodePrivate()
    , m_blendFactor(0.0f)
{
}

QLerpBlend::QLerpBlend(Qt3DCore::QNode *parent)
    : QAbstractClipBlendNode(*new QLerpBlendPrivate(), parent)
{
}

QLerpBlend::QLerpBlend(QLerpBlendPrivate &dd, Qt3DCore::QNode *parent)
    : QAbstractClipBlendNode(dd, parent)
{
}

QLerpBlend::~QLerpBlend()
{
}

Qt3DCore::QNodeCreatedChangeBasePtr QLerpBlend::createNodeCreationChange() const
{
    Q_D(const QLerpBlend);
    auto creationChange = QClipBlendNodeCreatedChangePtr<QLerpBlendData>::create(this);
    QLerpBlendData &data = creationChange->data;
    data.blendFactor = d->m_blendFactor;
    return creationChange;
}

/*!
    \qmlproperty real LerpBlend::blendFactor

    Specifies the blending factor between 0 and 1 to control the blending of
    two animation clips.
*/
/*!
    \property QLerpBlend::blendFactor

    Specifies the blending factor between 0 and 1 to control the blending of
    two animation clips.
 */
float QLerpBlend::blendFactor() const
{
    Q_D(const QLerpBlend);
    return d->m_blendFactor;
}

void QLerpBlend::setBlendFactor(float blendFactor)
{
    Q_D(QLerpBlend);
    if (d->m_blendFactor == blendFactor)
        return;

    d->m_blendFactor = blendFactor;
    emit blendFactorChanged(blendFactor);
}

/*!
    \qmlproperty list<AnimationClip> LerpBlend::clips

    Holds the list of AnimationClip nodes against which the blending is performed.

    \note Only the two first AnimationClip are used, subsequent ones are ignored
*/


/*!
    \fn void QLerpBlend::addClip(QAnimationClip *clip);
    Adds a \a clip to the blending node's clips list.

    \note Only the two first AnimationClip are used, subsequent ones are ignored
 */

/*!
    \fn void QLerpBlend::removeClip(QAnimationClip *clip);
    Removes a \a clip from the blending node's clips list.
 */

/*!
    \fn QVector<QAnimationClip *> QLerpBlend::clips() const;
    Returns the list of QAnimationClip against which the blending is performed.
 */

} // Qt3DAnimation

QT_END_NAMESPACE
