#pragma once
#include <cstdint>
#include <vector>
#include "Math.hpp"

class Actor
{
public:
  enum State
  {
    EActive,
    EPaused,
    EDead
  };

  /**
   * Constructs an actor.
   * @param game pointer to the game
   */
  Actor(class Game *game);

  /**
   * Destructs actor.
   */
  virtual ~Actor();

  /**
   * Adds a component to actor.
   * @param component pointer to component being added
   */
  void AddComponent(class Component *component);

  /**
   * Gets actor's forward-pointing unit vector.
   * @return actor's forward-pointing unit vector
   */
  Vector2 GetForward() const
  {
    return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation));
  }

  /**
   * Gets game
   * @return pointer to game.
   */
  class Game *GetGame() { return mGame; }

  /**
   * Gets actor's position.
   * @return actor's position
   */
  const Vector2 &GetPosition() const { return mPosition; }

  /**
   * Gets actor's rotational position.
   * @return actor's rotational position
   */
  float GetRotation() const { return mRotation; }

  /**
   * Gets actor's scale.
   * @return actor's scale
   */
  float GetScale() const { return mScale; }

  /**
   * Gets actor's current state.
   * @return actor's current state.
   */
  State GetState() const { return mState; }

  /**
   * Removes component from actor
   * @param component pointer to component being removed
   */
  void RemoveComponent(class Component *component);

  /**
   * Updates actor's controller when called by the game.
   * @param keyState state of the keyboard
   */
  void RunController(const uint8_t *keyState);

  /**
   * Updates actor's model when called by the game.
   * @param deltaTime change of time
   */
  void RunModel(float deltaTime);

  /**
   * Sets actor's position.
   * @param pos updated position
   */
  void SetPosition(const Vector2 &pos) { mPosition = pos; }

  /**
   * Sets actor's rotational position.
   * @param rotation updated rotational position
   */
  void SetRotation(float rotation) { mRotation = rotation; }

  /**
   * Sets actor's scale.
   * @param scale updated scale
   */
  void SetScale(float scale) { mScale = scale; }

  /**
   * Sets actor's state
   * @param updated state
   */
  void SetState(State state) { mState = state; }

protected:
  /**
   * Updates the actor's components.
   * @param deltaTime change of time
   */
  void RunComponents(float deltaTime);

  /**
   * Performs any special overrides to the actor's controller.
   * @param keystate state of the keyboard
   */
  virtual void RunControllerOverrides(const uint8_t *keyState) {}

  /**
   * Performs any special overrides to the model.
   * @param deltaTime change of time
   */
  virtual void RunModelOverrides(float deltaTime) {}

  State mState;      // current state
  Vector2 mPosition; // translational position
  float mScale;      // scale
  float mRotation;   // rotational position

  std::vector<class Component *> mComponents; // actor's components
  class Game *mGame;                          // game
};
