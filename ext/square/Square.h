#include <SDL.h>
#include <iostream>

using namespace std;

namespace sqr
{
  class Square
  {
  public:
    Square();
    Square(int x, int y, int w, int h, int velY, int mGravity, SDL_Color color);

    // getters
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    // functions
    void jump();
    void render(SDL_Renderer *renderer);
    void handleEvent(SDL_Event &e, int jumpVel);

  private:
    int mWidth;
    int mHeight;
    int mX;
    int mY;
    int mVelY;
    int mGravity;
    SDL_Color mColor;
  };
}