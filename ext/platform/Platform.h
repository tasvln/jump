#include <SDL.h>
#include <iostream>

using namespace std;

namespace plt
{
  class Platform
  {
  public:
    // contructor
    Platform();
    Platform(const string &name, int w, int h, int x, int y, int speed, SDL_Color color);

    // getters
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getSpeed();

    // modifiers
    void updateSpeed(int newSpeed);

    // functions
    void renderPlatform(SDL_Renderer *renderer);

  private:
    string mName;
    SDL_Color mColor;
    int mX;
    int mY;
    int mSpeed;
    int mWidth;
    int mHeight;
  };
}