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
}