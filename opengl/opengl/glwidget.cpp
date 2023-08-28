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
#include "glwidget.h"
#include "glwidget.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
#if 0
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    glEnable(GL_DEPTH_TEST); // 启用深度测试

    // 设置顶点数据
    static const GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f
    };

    // 设置索引数据
    static const GLuint indices[] = {
        0, 1, 2, 3,
        4, 5, 6, 7,
        0, 4, 1, 5,
        2, 6, 3, 7,
        0, 3, 4, 7,
        1, 5, 2, 6
    };

    // 创建和绑定顶点缓冲对象
    QOpenGLBuffer vbo(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.allocate(vertices, sizeof(vertices));

    // 创建和绑定索引缓冲对象
    QOpenGLBuffer ibo(QOpenGLBuffer::IndexBuffer);
    ibo.create();
    ibo.bind();
    ibo.allocate(indices, sizeof(indices));

    // 创建和编译顶点着色器
    QOpenGLShader vertexShader(QOpenGLShader::Vertex);
    vertexShader.compileSourceCode(R"(
        attribute vec3 position;
        uniform mat4 matrix;
        void main() {
            gl_Position = matrix * vec4(position, 1.0);
        })");

    // 创建和编译片段着色器
    QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
    fragmentShader.compileSourceCode(R"(
        void main() {
            gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
        })");

    // 创建和链接着色器程序
    QOpenGLShaderProgram shaderProgram;
    shaderProgram.addShader(&vertexShader);
    shaderProgram.addShader(&fragmentShader);
    shaderProgram.link();
    shaderProgram.bind();

    // 设置顶点属性
    shaderProgram.enableAttributeArray("position");
    shaderProgram.setAttributeBuffer("position", GL_FLOAT, 0, 3);

    // 设置投影矩阵
    QMatrix4x4 projectionMatrix;
    projectionMatrix.perspective(45.0f, width() / height(), 0.1f, 100.0f);
    shaderProgram.setUniformValue("matrix", projectionMatrix);
#endif

    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLWidget::paintGL()
{
#if 0
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清除颜色缓冲区和深度缓冲区

    // 绘制立方体
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, nullptr);
#endif

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex3f(-0.5, -0.5, 0);
    glColor3f(0, 1, 0);
    glVertex3f(0.5, -0.5, 0);
    glColor3f(0, 0, 1);
    glVertex3f(0, 0.5, 0);
    glEnd();
}
