#include "Text.h"

namespace txt
{
  Text::Text(const string &str)
  {
    mTexture = NULL;
    mText = str;
    mWidth = 0;
    mHeight = 0;
  }

  Text::~Text()
  {
    free();
  }

  string Text::getText() const
  {
    return mText;
  }

  int Text::getWidth() const
  {
    return mWidth;
  }

  int Text::getHeight() const
  {
    return mHeight;
  }

  void Text::renderText(SDL_Renderer *renderer, TTF_Font *font, SDL_Color color)
  {
    free();

    SDL_Surface *surface = TTF_RenderText_Solid(font, mText.c_str(), color);

    if (!surface)
    {
      std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
    }

    mTexture = SDL_CreateTextureFromSurface(renderer, surface);

    if (mTexture)
    {
      mWidth = surface->w;
      mHeight = surface->h;
    }

    SDL_FreeSurface(surface);
  }

  void Text::setText(const std::string &newText, SDL_Renderer *renderer, TTF_Font *font, SDL_Color color)
  {
    mText = newText;
    renderText(renderer, font, color);
  }

  void Text::render(int x, int y, SDL_Renderer *renderer)
  {
    SDL_Rect destRect = {x, y, mWidth, mHeight};
    SDL_RenderCopy(renderer, mTexture, nullptr, &destRect);
  }

  void Text::free()
  {
    if (mTexture)
    {
      SDL_DestroyTexture(mTexture);
      mTexture = NULL;
    }
  }
}