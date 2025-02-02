#include <SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    int getSpeed() const;

    // modifiers
    void updateSpeed(int newSpeed);

    // functions
    void render(SDL_Renderer *renderer);
    void movePlatform();
    void addObstacles(vector<SDL_Rect> &rects, const int platformY, const int windowW, int obsW, int obsH);
    void spawnObstacles(SDL_Renderer *renderer, const vector<SDL_Rect> &rects, SDL_Color color);
    void updateObstacles(vector<SDL_Rect> &rects, int speed, int &score);

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