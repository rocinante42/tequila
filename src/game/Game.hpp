#ifndef GAME_HPP
#define GAME_HPP

class Game
{
private:
  // ...
public:
  Game();
  ~Game();
  void Initialize();
  void Run();
  void ProcessInput();
  void Update();
  void Render();
  void Destroy();
  // ...
};

#endif // GAME_HPP