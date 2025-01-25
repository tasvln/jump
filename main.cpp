#include "main.h"

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
      int windowWidth = window.getWidth();
      int platformHeight = 80;
      int sqrSize = 20;
      int platformBottomY = window.getHeight() - platformHeight;
      int plyrBottomY = platformBottomY - sqrSize;

      int pltSpeed = 1;
      SDL_Color pltColor = {0, 0, 0};
      SDL_Color plyrColor = {0, 0, 0};

      Platform platform("Pltfm", windowWidth, platformHeight, 0, platformBottomY, 1, pltColor);
      Square square(20, plyrBottomY, sqrSize, sqrSize, 0, 1, false, plyrColor);

      int jumpVel = -20;

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

            square.handleEvent(evt, jumpVel);
          }

          platform.movePlatform();

          square.jumpCycle(platform.getY(), platform.getHeight());

          cout << "y:" << square.getY() << endl;

          window.clearScreen(0xFF, 0xFF, 0xFF, 0xFF);

          platform.render(window.getRenderer());
          square.render(window.getRenderer());

          window.presentRender();
        }
      }
    }
  }

  closeApp();

  return 0;
}