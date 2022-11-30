#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourceHandler.h"
#include "Menu.h"
#include <memory>
#include "Player.h"
#include "tmxlite/Map.hpp"
#include "tmxlite/TileLayer.hpp"//multipled "multiple definition" errors on home pc, clueless as to why.
#include <vector>
#include "TileHandler.h"
#include <cmath>
#include "GhostHandler.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

  void collisionHandler();
  bool ghostCollisionHandler();

  sf::Clock inputTimer;

  bool ghost_collided = false;

 private:
  sf::RenderWindow& window;
  //std::unique_ptr<ResourceHandler> resources;

  //Menu* menu;
  std::unique_ptr<Player> player;
  std::unique_ptr<Menu> menu;
  std::unique_ptr<TileHandler> tileHandler;
  std::unique_ptr<GhostHandler> ghost;
  std::unique_ptr<GhostHandler> ghost2;
  std::unique_ptr<GhostHandler> ghost3;
  std::unique_ptr<GhostHandler> ghost4;

  sf::Texture pink_ghost_texture;
  sf::Texture blue_ghost_texture;

  sf::Texture tileMap;
  tmx::Map map;

  int menu_selected = 1;

  enum gameScreen
  {
    MENU_SCREEN,
    GAME_SCREEN,
    PAUSE_SCREEN,
    WIN_SCREEN,
    LOSE_SCREEN
  };

  enum gameScreen game_state = gameScreen::MENU_SCREEN;

  enum activeLevel
  {
    LEVEL_1,
    LEVEL_2,
    LEVEL_3
  };

  bool paused = false;
  int score = 0;

  sf::Text score_text;
  sf::Text score_text_int;
  sf::Font game_font;
};

#endif // PLATFORMER_GAME_H