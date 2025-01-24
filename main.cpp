#include "main.h"

using namespace wdw;

bool loadMedia()
{
  bool loading = false;

  return loading;
}

void closeApp()
{
  SDL_Quit();
}

int main(int argc, char *argv[])
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }
  else
  {
    Window window("Jump", SCREEN_WIDTH, SCREEN_HEIGHT);

    if (!window.init())
    {
      printf("Failed to initialize Window!\n");
    }
    else
    {
      if (loadMedia())
      {
        printf("Failed to load Images/Textures!\n");
      }
      else
      {
        bool isRunning = true;
        SDL_Event evt;

        while (isRunning)
        {
          while (SDL_PollEvent(&evt) != 0)
          {
            if (evt.type == SDL_QUIT)
            {
              isRunning = false;
            }
          }

          window.clearScreen(0xFF, 0xFF, 0xFF, 0xFF);

          window.presentRender();
        }
      }
    }
  }

  closeApp();

  return 0;
}