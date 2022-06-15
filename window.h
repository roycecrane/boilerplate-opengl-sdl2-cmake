#include<SDL.h>
#include <stdio.h>

class Window{

    SDL_Window * m_window; 
    SDL_GLContext m_context; 
    int m_width; int m_height; 
    bool context_ok; bool window_ok; 

    public:

    Window(const int width, const int height): 
                                                m_width{width},
                                                m_height{height}, 
                                                m_window{nullptr},
                                                m_context{nullptr},
                                                context_ok{false}, 
                                                window_ok{false} 
                                                { init(); }

    ~Window();

    bool init();

    inline SDL_Window * getWindow(){ return this -> m_window; }

    inline void setWindowSize(const int width, const int height){
        m_width = width; m_height = height;
    }
};

