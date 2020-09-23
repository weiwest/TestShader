#include "MyShader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

std::string MyShader::getShaderContent(std::string path)
{
    std::ifstream File(path.c_str());
    std::stringstream st;
    st << File.rdbuf();
    File.close();
    return st.str();
}

MyShader::MyShader(std::string vPath, std::string fPath)
{
    //���붥����ɫ��
    std::string vst = getShaderContent(vPath);
    const char* vShader = vst.c_str();

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShader, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "error compile vertexshader" << infoLog << std::endl;
    }

    //����Ƭ����ɫ��
    std::string fst = getShaderContent(fPath);
    const char* fShader = fst.c_str();

    unsigned int fragShader;
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fShader, NULL);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
        std::cout << "error compile fragShader" << infoLog << std::endl;
    }

    //������ɫ�����ӵ�һ����ɫ��������
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragShader);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
    }

}

MyShader::~MyShader()
{

}

void MyShader::use()
{
    glUseProgram(ID);
}


void MyShader::setBool(const std::string& name, bool value)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
// ------------------------------------------------------------------------
void MyShader::setInt(const std::string& name, int value)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

int MyShader::getInt(const std::string& name)
{
    return glGetUniformLocation(ID, name.c_str());
    
}