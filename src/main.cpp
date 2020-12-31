#include <stdio.h>
#include <iostream>


#include "Window.h"
#include "Triangle.h"
#include "Vertex.h"
#include "Texture.h"
#include "Square.h"
#include "Transform.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main()
{
    //创建窗口
    //Window::createWindow();

    //画三角形
    //Triangle::createTriangle();

     //顶点着色器作用
    //Vertex::createVertex();

    //渲染三角形纹理
    //Texture::createTexture();

    //渲染矩形纹理
    Square::createSquare();

    //各种变换
    //Transform::createTransform();

    return 0;
}

