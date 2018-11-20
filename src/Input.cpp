#include "headers/Engine.h"

void Engine::input(float elapsedTime) {

  // Accessing the menu
  if (Keyboard::isKeyPressed(Keyboard::Escape)) {
    m_menuActive = !m_menuActive;
    m_playing = !m_playing;
    m_window.close();
  }

  // Gameplay specific stuff goes in here
  if (m_playing) {

    // If the player wants to switch characters
    if (Keyboard::isKeyPressed(Keyboard::E)) {
      // We also want to make sure the player doesn't switch too often
      if (m_timeSinceSwitch >= m_playerSwitchCooldown) {
        m_isHuman = !m_isHuman;
        m_timeSinceSwitch = 0;
      }
    }

    // We will handle character specific movements in their own classes
    if (m_isHuman)
      m_human.handleInput(elapsedTime);
    else
      m_demon.handleInput(elapsedTime);
  }
}
