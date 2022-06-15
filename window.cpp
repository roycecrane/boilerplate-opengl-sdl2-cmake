#include<iostream>
#include<GL/glew.h>
#include "window.h"

bool Window::init(){
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            fprintf(stderr, "Failed to initialize SDL video\n");
            return false;
        }
        m_window = SDL_CreateWindow( "BOILERPLATE OPENGL",
                                      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                      m_width, m_height, 
                                      SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL );
        
        if( m_window == NULL ) {
            fprintf(stderr, "Failed to create main window\n");
            SDL_Quit();
            return false;
        } else { window_ok = true; }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
        // SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

         m_context = SDL_GL_CreateContext(m_window);

        if ( m_context == NULL ) {
            fprintf(stderr, "Failed to create GL context\n");
            return false;
        } else { context_ok = true; }

        GLenum err;

        glewExperimental = GL_TRUE; 

        err = glewInit();
        if ( err != GLEW_OK ) {
            fprintf(stderr, "Failed to init GLEW\n");
            return false;
        }

        // SDL_GL_SetSwapInterval(1); // Use VSYNC
        return true;
}
Window::~Window(){
    if ( window_ok == true ) {
        if( context_ok == true ) SDL_GL_DeleteContext(m_context);
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}