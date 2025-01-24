#include <SDL.h>
#include <string>
#include <iostream>

using namespace std;

namespace ply
{
  class Player
  {
  public:
    // getters
    string getPlayerName();
    int getPlayerScore();
    int getPlayerHighScore();

    // modifiers
    bool changePlayerName();

  private:
    string mName;
    int mScore;
    int mHighScore;
  };
}