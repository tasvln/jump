#include <SDL.h>
#include <iostream>

using namespace std;

template <typename T>
namespace obj
{
  class Object
  {
  public:
    // contructor
    Object();
    Object(int x, int y);
    // getters
    int getX();
    int getY();
    int getWidth();
    int getHeight();

  private:
    string mName;
    SDL_Color color;
    int mX;
    int mY;
    int mWidth;
    int mHeight;
  }
}