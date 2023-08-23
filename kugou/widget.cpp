/*
 * Copyright (C) 2022 ~ 2023 Deepin Technology Co., Ltd.
 *
 * Author:     songwentao <songwentao@uniontech.com>
 *
 * Maintainer: songwentao <songwentao@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "widget.h"

#include <QApplication>
#include <QScreen>
#include <QDebug>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    initUi();
    initStyle();
}

Widget::~Widget()
{

}

void Widget::initUi()
{
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    this->resize(400, 300);
    QScreen *primaryScreen = qApp->primaryScreen();
    QRect rect = primaryScreen->virtualGeometry();
    move(rect.center().x() - width() / 2, rect.center().y() - height() / 2);

    qApp->installEventFilter(this);
}

void Widget::initStyle()
{
    setStyleSheet("QWidget{background: red;}");
}

void Widget::playAnimation(const int aniDuring = 300)
{
    int x = this->x();
    int y = this->y();
    int width = this->width();
    int height = this->height();

    // 创建一个位置属性动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setDuration(aniDuring); // 设置动画持续时间
    animation->setStartValue(QRect(x, y, width, height)); // 设置起始位置和大小
    animation->setEndValue(QRect(x, y + height/2, width, 0)); // 设置结束位置和大小

    animation->start();

    QObject::connect(animation, &QParallelAnimationGroup::finished, this, &QWidget::close);
}

bool Widget::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::Close) {
        playAnimation();
        return true;
    }

    return QWidget::eventFilter(object, event);
}

void Widget::onClick()
{
    #if 0
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
//    group->setDirection(QAbstractAnimation::Forward);

    QPropertyAnimation *heightAni = new QPropertyAnimation(this, "size");
    heightAni->setDirection(QAbstractAnimation::Forward);
    heightAni->setEasingCurve(QEasingCurve::OutQuad);
    heightAni->setDuration(1000);
    heightAni->setStartValue(size());
    heightAni->setKeyValueAt(0.8, QSize(width(), 10));
    heightAni->setKeyValueAt(0.9, QSize(width() / 2, 5));
    heightAni->setEndValue(QSize(1, 1));

    QPropertyAnimation *posAni = new QPropertyAnimation(this, "pos");
    posAni->setDirection(QAbstractAnimation::Backward);
    posAni->setEasingCurve(QEasingCurve::Linear);
    posAni->setDuration(1000);
    posAni->setStartValue(pos());
    posAni->setEndValue(QPoint(geometry().center().x(), geometry().center().y()));

    group->addAnimation(heightAni);
    group->addAnimation(posAni);

    group->start();

    QObject::connect(group, &QParallelAnimationGroup::finished, this, &QWidget::close);
#endif
}
