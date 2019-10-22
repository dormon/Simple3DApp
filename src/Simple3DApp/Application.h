#pragma once

#include <SDL2CPP/Window.h>
#include <Simple3DApp/simple3dapp_export.h>
#include <Simple3DApp/Fwd.h>
#include <imguiSDL2OpenGL/imgui.h>

class simple3DApp::Application {
 public:
  SIMPLE3DAPP_EXPORT Application(int argc, char* argv[],uint32_t contextVersion = 450u);
  SIMPLE3DAPP_EXPORT virtual ~Application();
  SIMPLE3DAPP_EXPORT void         start();
  SIMPLE3DAPP_EXPORT void         swap();
  SIMPLE3DAPP_EXPORT virtual void mouseMove(SDL_Event const& e);
  SIMPLE3DAPP_EXPORT virtual void mouseButton(SDL_Event const& e, bool down);
  SIMPLE3DAPP_EXPORT virtual void key(SDL_Event const& e, bool down);
  SIMPLE3DAPP_EXPORT virtual void resize(uint32_t x, uint32_t y);
  SIMPLE3DAPP_EXPORT virtual void draw();
  SIMPLE3DAPP_EXPORT virtual void init();
  SIMPLE3DAPP_EXPORT virtual void deinit();

 protected:
  std::shared_ptr<sdl2cpp::MainLoop>      mainLoop;
  std::shared_ptr<sdl2cpp::Window>        window;
  std::unique_ptr<imguiSDL2OpenGL::Imgui> imgui;
  int                                     argc;
  char**                                  argv;
};

