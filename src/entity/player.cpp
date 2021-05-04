#include "player.hpp"

Player::Player(int x, int y, int weight, int colorInder) : Rigid(x, y, weight, colorInder) {}

void Player::jump(unsigned int strenght)
{
  m_Acc = strenght * -1;
}
