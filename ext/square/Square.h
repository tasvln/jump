#include <SDL.h>
#include <iostream>

using namespace std;

namespace sqr
{
  class Square
  {
  public:
    Square();
    Square(int x, int y, int w, int h, int velY, int gravity, bool grounded, SDL_Color color);

    // getters
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    // functions
    void render(SDL_Renderer *renderer);
    void handleEvent(SDL_Event &e, int jumpVel);
    void jumpCycle(int platformY, int windowHeight);

  private:
    int mWidth;
    int mHeight;
    int mX;
    int mY;
    int mVelY;
    int mGravity;
    bool mGrounded;
    SDL_Color mColor;
  };
}