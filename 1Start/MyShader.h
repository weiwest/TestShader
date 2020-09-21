#pragma once

#include <string>

class MyShader
{
public:
    unsigned int ID;
    MyShader(std::string vPath, std::string fPath);
    ~MyShader();
    void use();
    void setBool(const std::string& name, bool value);
    void setInt(const std::string& name, int value);

private:
    
    std::string getShaderContent(std::string path);

};

