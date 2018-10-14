#pragma once

#include<SDL2CPP/Window.h>
#include <imguiSDL2OpenGL/imgui.h>

namespace simple3DApp{

class Application{
  public:
    Application(int argc,char*argv[]);
    virtual ~Application();
    void start();
    void swap();
    virtual void mouseMove(SDL_Event const&e);
    virtual void key(SDL_Event const&e,bool down);
    virtual void resize(uint32_t x,uint32_t y);
    virtual void draw();
    virtual void init();
    virtual void deinit();
  protected:
    std::shared_ptr<sdl2cpp::MainLoop>mainLoop;
    std::shared_ptr<sdl2cpp::Window>window;
    std::unique_ptr<imguiSDL2OpenGL::Imgui>imgui;
    int argc;
    char**argv;
};

}
