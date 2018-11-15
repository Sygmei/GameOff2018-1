#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Level.h"
#include "NLLinkedList.h"
#include <experimental/filesystem>
#include <iostream>

using namespace sf;
namespace fs = std::experimental::filesystem;

class Engine {
private:
  // TODO: have the player accelerate as they fall
  const int GRAVITY = 300;

  // Our display window
  RenderWindow m_window;

  // We only need one view for the main character, one for the HUD, one
  // for the background, and one for the pause menu
  View m_mainView;
  View m_BGView;
  View m_HUDView;
  View m_menuView;

  // If the menu is shown
  bool m_menuActive;

  // This will be false when we are swapping levels, paused, etc.
  bool m_playing = true;

  // This will signify whether the player is the first or second character
  bool m_player1;
  // There has to be some cooldown for switching characters
  float m_playerSwitchCooldown = 2;
  // And a tracker for how long it's been
  float m_timeSinceSwitch;

  // Our current level
  Level m_currentLevel;
  // And all of our levels, in our custom NLLinkedList class
  NLLinkedList<Level> m_levels;
  // We also need to keep track of where to put the player based on where
  // they enter a level from
  map<Level, map<Direction, Vector2f>> m_levelStartingPositions;
  // Both of these variables above will be initialized in loadLevels();

  // Whether or not we need a new level, along with the direction to go
  // This will be set to the value of NONE if we don't need to change levels
  Direction m_directionToMove;

  // Our abstracted functions
  // These are defined in their own files according to their name
  void input();
  void draw();
  void update(float elapsedTime);
  // This function, not to be confused with loadLevel, loads all levels in the
  // levels/ folder, and initializes a few variables above
  void loadLevels();

public:
  Engine();

  void run();

};
