#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

// headers
#include "ext/window/Window.h"
#include "ext/platform/Platform.h"
#include "ext/square/Square.h"
#include "ext/text/Text.h"

using namespace wdw;
using namespace plt;
using namespace sqr;
using namespace txt;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

TTF_Font *gFont = NULL;

void closeApp();