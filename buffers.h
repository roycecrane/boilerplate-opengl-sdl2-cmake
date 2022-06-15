#include<GL/glew.h>
#include <iostream>
#include <map>

class Buffers{
    std::map<std::string, GLuint> buffs;
    public:
    void setBuff(const std::string name, const GLenum type , const GLsizeiptr size , GLfloat const data[] );
    inline GLuint const getBuff(const std::string& name){  return buffs[name]; }
};
class VertexAttribs{
    std::map<std::string, GLint> attrib_locations;
    GLuint VertexArrayID;
    public:
    void addAttrib(const GLuint shader,const std::string name, const int size, const int stride);
    inline GLuint getAttrib(std::string name){
        return attrib_locations[name];
    }
};