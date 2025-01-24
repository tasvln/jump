#include "Window.h"

using namespace wdw;

namespace wdw
{
  // contructors
  Window::Window()
  {
    mTitle = "Window";
    mWidth = 900;
    mHeight = 600;

    window = nullptr;
    renderer = nullptr;
  }

  Window::Window(const string &title, int w, int h)
  {
    mTitle = title;
    mWidth = w;
    mHeight = h;

    window = nullptr;
    renderer = nullptr;
  }

  Window::~Window()
  {
    this->free();
  }

  // functions
  bool Window::init()
  {
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (!window)
    {
      std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
      return;
    }
    else
    {
      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

      if (!renderer)
      {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        this->free();
        return;
      }
    }

    return (window != NULL && renderer != NULL)
  }

  bool Window::free()
  {
    if (window)
      SDL_DestroyWindow(window);
    if (renderer)
      SDL_DestroyRenderer(renderer);

    mTitle = "";
    mWidth = 0;
    mHeight = 0;
  }

  void Window::clearScreen(int r, int g, int b, int a)
  {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
  }

  void Window::presentRender()
  {
    SDL_RenderPresent(renderer);
  }

  // getters
  string Window::getTitle()
  {
    return mTitle;
  }

  int Window::getWidth()
  {
    return mWidth;
  }

  int Window::getHeight()
  {
    return mHeight;
  }

  SDL_Renderer *getRenderer() const
  {
    return renderer;
  }

  // modifiers
  bool Window::setWindowTitle(string &title)
  {
    bool done = false;

    if (title != "")
    {
      mTitle = title;
      done = true;
    }

    return done
  }
}