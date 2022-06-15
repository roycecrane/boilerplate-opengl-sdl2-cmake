#ifndef BUFFERS_H
#define BUFFERS_H
#include "buffers.h"

void Buffers::setBuff(const std::string name, const GLenum type , const GLsizeiptr size , GLfloat const data[]){
    GLuint buff;
    glGenBuffers(1, &buff);
    buffs.insert(std::pair<std::string, GLuint>(name, buff));
    glBindBuffer(GL_ARRAY_BUFFER, buff);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
void VertexAttribs::addAttrib(const GLuint shader,const std::string name, const int size, const int stride){
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);
        GLint attr_loc = glGetAttribLocation(shader, name.c_str());
        attrib_locations.insert(std::pair<std::string, GLuint>(name, attr_loc));
        glEnableVertexAttribArray(attr_loc);
        int siz= attrib_locations.size();
        glVertexAttribPointer(siz-1, 3, GL_FLOAT, GL_FALSE , stride , (void*)0);
    }

#endif 