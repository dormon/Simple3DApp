#include <Simple3DApp/Application.h>
#include <geGL/geGL.h>

namespace simple3DApp {

  Application::Application(int argc, char* argv[],uint32_t contextVersion) : argc(argc), argv(argv)
  {
    mainLoop = std::make_shared<sdl2cpp::MainLoop>();
    mainLoop->setIdleCallback([&](){
      imgui->newFrame(window->getWindow());
      draw();
    });//std::bind(&Application::draw, this));
    window = std::make_shared<sdl2cpp::Window>(512, 512);
    window->setEventCallback(SDL_MOUSEMOTION, [&](SDL_Event const& e) {
      mouseMove(e);
      return true;
    });
    window->setEventCallback(SDL_MOUSEBUTTONDOWN, [&](SDL_Event const& e) {
      mouseButton(e, true);
      return true;
    });
    window->setEventCallback(SDL_MOUSEBUTTONUP, [&](SDL_Event const& e) {
      mouseButton(e, false);
      return true;
    });
    window->setEventCallback(SDL_KEYDOWN, [&](SDL_Event const& e) {
      key(e, true);
      return true;
    });
    window->setEventCallback(SDL_KEYUP, [&](SDL_Event const& e) {
      key(e, false);
      return true;
    });
    mainLoop->setEventCallback(SDL_QUIT,[&](SDL_Event const&){
      mainLoop->stop();
      return true;
    });
    window->setWindowEventCallback(SDL_WINDOWEVENT_RESIZED,[&](SDL_Event const& e){
      resize(e.window.data1,e.window.data2);
      return true;
    });
    window->createContext("rendering", contextVersion, sdl2cpp::Window::CORE,
                          sdl2cpp::Window::DEBUG);
    mainLoop->addWindow("primaryWindow", window);
    window->makeCurrent("rendering");
    ge::gl::init(SDL_GL_GetProcAddress);
    ge::gl::setHighDebugMessage();

    imgui = std::make_unique<imguiSDL2OpenGL::Imgui>(window->getWindow());

    mainLoop->setEventHandler([&](SDL_Event const&event){
      return imgui->processEvent(&event);
    });
  }
  Application::~Application(){
    imgui = nullptr;
  }

  void Application::start()
  {
    init();
    (*mainLoop)();
    deinit();
  }

  void Application::swap() { 
    imgui->render(window->getWindow(), window->getContext("rendering"));
    window->swap(); 
  }

  void Application::mouseMove(SDL_Event const&) {}

  void Application::mouseButton(SDL_Event const&, bool) {}

  void Application::key(SDL_Event const&, bool) {}
  
  void Application::resize(uint32_t,uint32_t){}

  void Application::draw() {}

  void Application::init() {}

  void Application::deinit() {}

}  // namespace simple3DApp
