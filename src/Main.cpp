#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <glm/glm.hpp>
#include <imgui/imgui.h>
#include <iostream>
#include <sol/sol.hpp>

#include "./game/Game.hpp"

int main()
{
  Game game;

  game.Run();

  game.Destroy();
  return 0;
}
