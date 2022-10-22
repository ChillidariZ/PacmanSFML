//
// Created by a2-noori on 21/10/2022.
//

#include "Player.h"

Player::Player()
{
  if(!playerTexture.loadFromFile("Data/Images/pacman.png"))
  {
    std::cout << "Player texture not loaded" << std::endl;
  }

  playerSprite.setTexture(playerTexture);

  playerSprite.setScale(0.15f, 0.15f);
}

Player::~Player()
{

}

void Player::playerInput()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    playerMovementState = playerMovement::MOVE_LEFT;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    playerMovementState = playerMovement::MOVE_RIGHT;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    playerMovementState = playerMovement::MOVE_UP;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    playerMovementState = playerMovement::MOVE_DOWN;
  }
}

void Player::playerMovement()
{
  switch(playerMovementState)
  {
    case MOVE_LEFT:
      playerSprite.move(5.f,0.f);
      std::cout << "Player move left" << std::endl;
      break;
    case MOVE_RIGHT:
      playerSprite.move(-5.f,0.f);
      std::cout << "Player move right" << std::endl;
      break;
    case MOVE_UP:
      playerSprite.move(0.f,0.5f);
      std::cout << "Player move up" << std::endl;
      break;
    case MOVE_DOWN:
      playerSprite.move(0.f,-0.5f);
      std::cout << "Player move down" << std::endl;
      break;
    case MOVE_STATIONARY:
      playerSprite.move(0.f,0.f);
      std::cout << "Player stationary" << std::endl;
      break;
  }
}
