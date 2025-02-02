#include "Platform.h"

namespace plt
{
  Platform::Platform()
  {
    mName = "Platform";
    mColor = {0, 0, 0};
    mX = 0;
    mY = 0;
    mSpeed = 1;
    mWidth = 900;
    mHeight = 400;
  }

  Platform::Platform(const string &name, int w, int h, int x, int y, int speed, SDL_Color color)
  {
    mName = name;
    mColor = color;
    mX = x;
    mY = y;
    mSpeed = speed;
    mWidth = w;
    mHeight = h;
  }

  // getters
  int Platform::getX() const
  {
    return this->mX;
  }

  int Platform::getY() const
  {
    return this->mY;
  }

  int Platform::getWidth() const
  {
    return this->mWidth;
  }

  int Platform::getHeight() const
  {
    return this->mHeight;
  }

  int Platform::getSpeed() const
  {
    return this->mSpeed;
  }

  // modifiers
  void Platform::updateSpeed(int newSpeed)
  {
    if (newSpeed > 0 && newSpeed != mSpeed)
    {
      mSpeed = newSpeed;
    }
  }

  void Platform::render(SDL_Renderer *renderer)
  {
    if (renderer)
    {
      SDL_SetRenderDrawColor(renderer, mColor.r, mColor.g, mColor.b, mColor.a);
      SDL_Rect rect = {mX, mY, mWidth, mHeight};
      SDL_RenderFillRect(renderer, &rect);
    }
  }

  void Platform::movePlatform()
  {
    mX -= mSpeed;
    mWidth += mSpeed;
  }

  void Platform::updateObstacles(vector<SDL_Rect> &rects, int speed, int &score)
  {
    for (auto it = rects.begin(); it != rects.end();)
    {
      it->x -= speed;

      if (it->x + it->w < 0)
      {
        score++;
        it = rects.erase(it);
      }
      else
      {
        ++it;
      }
    }
  }

  void Platform::addObstacles(vector<SDL_Rect> &rects, const int platformY, const int windowW, int obsW, int obsH)
  {
    int obsX = windowW;
    int obsY = platformY - obsH;

    rects.push_back({obsX, obsY, obsW, obsH});
  }

  void Platform::spawnObstacles(SDL_Renderer *renderer, const vector<SDL_Rect> &rects, SDL_Color color)
  {
    if (renderer)
    {
      SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
      for (const auto &obs : rects)
      {
        SDL_RenderFillRect(renderer, &obs);
      }
    }
  }
}