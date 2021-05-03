#pragma once

class Entity
{
protected:
  int m_X, m_Y, m_Acc, m_ColorIndex;
  bool m_Frozen;

public:
  /**
   * An Entity
   * @param x The x coordinate of the Entity
   * @param y The y coordinate of the Entity
   * @param colorIndex The palette color index of the Entity
   */
  Entity(int x, int y, int colorIndex);
  /**
   * Should be runned at each frame.
   */
  virtual void update();

  inline int getX() { return m_X; };
  inline int getY() { return m_Y; };
  /**
   * @returns The acceleration of the Entity.
   */
  inline int getAcc() { return m_Acc; };
  /**
   * @returns The palette color index of the Entity.
   */
  inline int getColorIndex() { return m_ColorIndex; };
  inline bool isFrozen() { return m_Frozen; };
  inline void setX(int x) { m_X = x; };
  inline void setY(int y) { m_Y = y; };
  inline void setFrozen(bool frozen) { m_Frozen = frozen; };
};
