#include<GL/glew.h>
#include<iostream>
#include<string>
#include<vector>

class Shader{
    public:
    Shader(){}
    GLuint InitShaders(const std::vector<std::string>& shaderSourceFiles);
    GLuint compileShaderSource(const std::string & sourceFile, const GLenum& type);
    const bool linkProgram(const GLuint& program); 
    std::string loadShader(const char *  location);
};