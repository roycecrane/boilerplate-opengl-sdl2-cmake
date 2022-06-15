#include<GL/glew.h>
#include<SDL.h>

#include<vector>
#include<map>

#include <fstream>
#include <string>

#include<iostream>

#include "window.h"
#include "shader.h"
#include "buffers.h"


const GLfloat verts[] = {
   -1.0f, -1.0f, 0.0f,
   -1.0f, 1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,

    1.0f, -1.0f, 0.0f,
    -1.0f, 1.0f, 0.0f,
    1.0f,  1.0f, 0.0f,
};     

std::string loadShader(const char * filePath){
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);
    if(!fileStream.is_open()){std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;return "";}
    std::string line = "";
    while(!fileStream.eof()){std::getline(fileStream, line);content.append(line + "\n"); }
    fileStream.close();
    return content;
}
                                 
template<typename T> void print(const T& item){ std::cout << item <<"\n"; }


void onFrameDraw(SDL_Window * window){
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0 , 6);
    SDL_GL_SwapWindow(window);
}

void runProgram(Window& win){
    int frameCount = 0;
    SDL_Window * window = win.getWindow();
    bool is_running = true;
    while (is_running) {
        onFrameDraw(window);
        SDL_Event event;    
        while (SDL_PollEvent(&event)) {
            if ( event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE ) {
                is_running = false;
                break;
            }
        }
        frameCount++;
    }
}
int main( int argv, char** args ) {

    auto vert = loadShader("../vert.glsl");
    auto frag = loadShader("../frag.glsl");
    std::vector<std::string> shaderFiles = {vert,frag}; 

    Window win(666,666);
    Shader shdr;
    Buffers buffs;
    VertexAttribs vtx;

    auto const program = shdr.InitShaders(shaderFiles);
    
    shdr.linkProgram(program);
    glUseProgram(program);

    buffs.setBuff("pos", GL_ARRAY_BUFFER, sizeof verts, verts);
    vtx.addAttrib(program,"pos",0,0);
    runProgram(win);
    print("GL ERROR CODE: ");
    print(glGetError());
     return 0;
}
