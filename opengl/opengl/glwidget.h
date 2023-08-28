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
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QObject>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};
#endif // GLWIDGET_H
