#include "Square.h"

namespace sqr
{
  Square::Square()
  {
    mX = 0;
    mY = 0;
    mWidth = 100;
    mHeight = 100;
    mColor = {0, 0, 0};
  }

  Square::Square(int x, int y, int w, int h, SDL_Color color)
  {
    mX = x;
    mY = y;
    mWidth = w;
    mHeight = h;
    mColor = color;
  }
  int Square::getX() const
  {
    return this->mX;
  }

  int Square::getY() const
  {
    return this->mY;
  }

  int Square::getWidth() const
  {
    return this->mWidth;
  }

  int Square::getHeight() const
  {
    return this->mHeight;
  }

  void Square::jump()
  {
  }

  void Square::render(SDL_Renderer *renderer)
  {
    if (renderer)
    {
      SDL_SetRenderDrawColor(renderer, mColor.r, mColor.g, mColor.b, mColor.a);
      SDL_Rect rect = {mX, mY, mWidth, mHeight};
      SDL_RenderFillRect(renderer, &rect);
    }
  }

  void Square::handleEvent(SDL_Event &e, int jumpVel)
  {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
      if (e.key.keysym.sym == SDLK_UP)
      {
        // int currX = mX;

        mY += jumpVel;
      }
    }
    else
    {
      if (e.type == SDL_KEYUP && e.key.repeat == 0)
      {
        if (e.key.keysym.sym == SDLK_UP)
        {
          mY -= jumpVel;
        }
      }
    }
  }
}