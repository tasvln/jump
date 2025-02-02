#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

using namespace std;

namespace txt
{
  class Text
  {
  public:
    Text(const string &str);
    ~Text();

    // getters
    string getText() const;
    int getWidth() const;
    int getHeight() const;

    // functions
    void renderText(SDL_Renderer *renderer, TTF_Font *font, SDL_Color color);

    void render(int x, int y, SDL_Renderer *renderer);
    void setText(const std::string &newText, SDL_Renderer *renderer, TTF_Font *font, SDL_Color color);

    void free();

  private:
    string mText;
    int mWidth;
    int mHeight;
    SDL_Texture *mTexture;
  };
}