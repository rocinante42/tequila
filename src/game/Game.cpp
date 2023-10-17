
#include "Game.hpp"
#include <iostream>
#include <SDL2/SDL.h>

////////////////////////// Constructor ///////////////////////

Game::Game()
{
  // TODO: Add the body of the function.
  std::cout << "Game constructor called." << std::endl;
  isRunning = false;
}

////////////////////////// Destructor ///////////////////////

Game::~Game()
{
  std::cout << "Game destructor called." << std::endl;
}

////////////////////////// INITIALIZE ///////////////////////

void Game::Initialize()
{
  // SDL initialization
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cerr << "Error initializing SDL" << std::endl;
    return;
  }
  // SDL window pointer
  window = SDL_CreateWindow(
      "Haferlocken",          // Window title
      SDL_WINDOWPOS_CENTERED, // Window x position
      SDL_WINDOWPOS_CENTERED, // Window y position
      1280,                   // Window width
      720,                    // Window height
      SDL_WINDOW_BORDERLESS   // Window flags
  );

  if (!window)
  {
    std::cerr << "Error creating SDL window" << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer)
  {
    std::cerr << "Error creating SDL renderer" << std::endl;
    return;
  }

  isRunning = true;
}

////////////////////////// RUN ///////////////////////

void Game::Run()
{
  while (isRunning)
  {
    ProcessInput();
    Update();
    Render();
  }
}

////////////////////////// PROCESS INPUT ///////////////////////

void Game::ProcessInput()
{
  SDL_Event sdlEvent;
  while (SDL_PollEvent(&sdlEvent))
  {
    switch (sdlEvent.type)
    {
    case SDL_QUIT:
      /* code */
      isRunning = false;
      break;
    case SDL_KEYDOWN:
      if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
      {
        isRunning = false;
      }
    default:
      break;
    }
  };
}

////////////////////////// UPDATE ///////////////////////////

void Game::Update()
{
}

////////////////////////// RENDER ///////////////////////////

void Game::Render()
{
  SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

////////////////////////// DESTROY ///////////////////////////

void Game::Destroy()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
