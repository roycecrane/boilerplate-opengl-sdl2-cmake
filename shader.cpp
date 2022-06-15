#include"shader.h"
#include <stdio.h>
#include <GL/GL.h>
#include<GL/glew.h>

#include <iostream>

GLuint Shader::InitShaders(const std::vector<std::string>& shaderSourceFiles){
    std::vector<GLenum> shaderTypes = { GL_VERTEX_SHADER, GL_FRAGMENT_SHADER };
    std::vector<GLuint> compiledShaders;
    GLuint program = glCreateProgram();

    for(auto i = 0; i < shaderSourceFiles.size(); i++){
        compiledShaders.push_back(
                            compileShaderSource(shaderSourceFiles[i], shaderTypes[i]));
    }
    for(auto s : compiledShaders){
        glAttachShader(program,s);
    }
    return program;
}

GLuint Shader::compileShaderSource(const std::string & sourceFile, const GLenum& type ){
    GLint status;
      GLuint shader = glCreateShader(type);
    char err_buf[512];
    const GLchar * source = (const GLchar *)sourceFile.c_str();
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    GLint is_compiled = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &is_compiled);
    if(is_compiled == GL_FALSE){
        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);        
        std::vector<GLchar> infoLog(1000);
        glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);
        glDeleteShader(shader);
        for(auto i : infoLog) std::cout << i;
    }
    return shader;
}

const bool Shader::linkProgram(const GLuint& program){
        glLinkProgram(program);
        GLint is_linked = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &is_linked);
        if(is_linked == GL_FALSE){
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);        
            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
            glDeleteProgram(program);
            for(auto i : infoLog) std::cout << i;
            return false;
        }
    return true;
}
