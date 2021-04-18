#pragma once
#include "Actor.hpp"

class Tower : public Actor
{
public:
  Tower(class Game *game);

private:
  void RunModelOverrides(float deltaTime) override;

  class MoveComponent *mMove;
  float mNextAttack;
  const float AttackTime = 2.5f;
  const float AttackRange = 100.0f;
};
