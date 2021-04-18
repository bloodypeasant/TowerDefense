#pragma once
#include "Actor.hpp"

class Enemy : public Actor
{
public:
  Enemy(class Game *game);
  ~Enemy();
  class CircleComponent *GetCircle() { return mCircle; }

private:
  void RunModelOverrides(float deltaTime) override;

  class CircleComponent *mCircle;
};
