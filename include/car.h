/**
 * @file car.h
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * @email sozhia.business@gmail.com
 * @brief Car class and its definitions
 * @version 0.1
 * @date 2020-11-06
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "maze.h"

class Car{
 private:
  unsigned int pos_X_;
  unsigned int pos_Y_;
  int sum_cost_;
  std::vector<unsigned int> radar_[4];

 public:
 ~Car();
  Car();
  Car(unsigned int x, unsigned int y);
  void SetPositionX(unsigned int x_value);
  void SetPositionY(unsigned int y_value);
  unsigned int GetPositionX();
  unsigned int GetPositionY();
  bool CheckAdjacentTiles(Tile& tile);
  void PathfinderAs(Maze& maze);
};