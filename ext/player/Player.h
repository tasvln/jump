#include <SDL.h>
#include <iostream>

using namespace std;

namespace plyr
{
  class Player
  {
  public:
    // constructor
    Player();
    Player(const string &name, int score, int mHighScore);

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