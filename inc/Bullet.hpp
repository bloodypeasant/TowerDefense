#pragma once
#include "Actor.hpp"

class Bullet : public Actor
{
public:
  Bullet(class Game *game);

private:
  void RunModelOverrides(float deltaTime) override;

  class CircleComponent *mCircle;
  float mLiveTime;
};
