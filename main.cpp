#include "main.h"

bool loadMedia()
{
  bool loading = true;

  gFont = TTF_OpenFont("lib/inter.ttf", 28);

  if (gFont == NULL)
  {
    printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
    loading = false;
  }

  return loading;
}

void closeApp()
{
  TTF_CloseFont(gFont);
  gFont = NULL;

  TTF_Quit();
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
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
      printf("Warning: Linear texture filtering not enabled!");
    }

    if (TTF_Init() == -1)
    {
      printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    }

    Window window("Jump", SCREEN_WIDTH, SCREEN_HEIGHT);

    if (!window.init())
    {
      printf("Failed to initialize Window!\n");
    }
    else
    {
      int score = 0;

      std::vector<SDL_Rect> obsVector;
      SDL_Color obsColor = {0, 0, 0};

      int windowWidth = window.getWidth();
      int platformHeight = 80;
      int sqrSize = 20;
      int platformBottomY = window.getHeight() - platformHeight;
      int plyrBottomY = platformBottomY - sqrSize;

      int pltSpeed = 1;
      SDL_Color pltColor = {0, 0, 0};
      SDL_Color plyrColor = {0, 0, 0};
      SDL_Color txtColor = {0, 0, 0};

      Platform platform("Pltfm", windowWidth, platformHeight, 0, platformBottomY, 200, pltColor);
      Square square(120, plyrBottomY, sqrSize, sqrSize, 0, 1, false, 0, plyrColor);

      int jumpVel = -10;

      Text overText("Game Over, Press 'R' to restart");
      Text scoreText("Score: " + to_string(score));

      if (!loadMedia())
      {
        printf("Failed to load Images/Textures!\n");
      }
      else
      {
        int frames = 0;
        bool isRunning = true;
        bool gameOver = false;
        SDL_Event evt;

        while (isRunning)
        {
          while (SDL_PollEvent(&evt) != 0)
          {
            if (evt.type == SDL_QUIT)
            {
              isRunning = false;
            }

            if (gameOver && evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_r)
            {
              obsVector.clear();
              gameOver = false;
              score = 0;
            }

            if (!gameOver)
            {
              square.handleEvent(evt, jumpVel);
            }
          }

          if (!gameOver)
          {
            frames++;
            if (frames > (60 * 4))
            {
              // spawn obs
              platform.addObstacles(obsVector, platformBottomY, windowWidth, 40, 80);
              frames = 0;
            }

            square.jumpCycle(platform.getY(), platform.getHeight());

            platform.movePlatform();

            platform.updateObstacles(obsVector, 1, score);

            for (const auto &obs : obsVector)
            {
              if (square.checkCollision(obs))
              {
                gameOver = true;
                overText.renderText(window.getRenderer(), gFont, txtColor);
              }
              else
              {
                // score++;
                scoreText.setText("Score: " + std::to_string(score), window.getRenderer(), gFont, txtColor);
              }
            }
          }

          window.clearScreen(0xFF, 0xFF, 0xFF, 0xFF);

          scoreText.renderText(window.getRenderer(), gFont, txtColor);
          scoreText.render(10, 10, window.getRenderer());

          if (!gameOver)
          {
            platform.spawnObstacles(window.getRenderer(), obsVector, obsColor);
          }

          platform.render(window.getRenderer());

          square.render(window.getRenderer());

          if (gameOver)
          {
            overText.render((window.getWidth() - overText.getWidth()) / 2, (window.getHeight() - overText.getHeight()) / 2, window.getRenderer());
          }

          window.presentRender();
        }
      }
    }
  }

  closeApp();

  return 0;
}