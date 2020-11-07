/**
 * @file tile.h
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * @email sozhia.business@gmail.com
 * @brief Tile class and its definitions
 * @version 0.1
 * @date 2020-11-06
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include "cell.h"
#include <limits>

class Tile{
 private:
  unsigned int x_pos_, y_pos_;
  int cost_;
  bool exit_=false;
  bool entrance_=false;
  bool visited_;
 public:
  std::vector<Tile>& neighbours_;
  std::vector<Tile>& connected_;
  std::vector<std::vector<Cell>>& cell_tile_;
  ~Tile();
  Tile();
  void SetCost(int cost);
  int GetCost();
  void SetVisited(bool status);
  bool GetVisited() {return visited_;}
  void SetExit() {exit_=true;entrance_=false;}
  void SetEntrance() {exit_=false;entrance_=true;}
  unsigned int GetPosX();
  unsigned int GetPosY();
  void SetPos(unsigned int x, unsigned int y);
  void FillTile(Cell& wall_cell, Cell& path_cell);
  void CheckNorth(Cell& wall_cell);
  void CheckSouth(Cell& wall_cell);
  void CheckEast(Cell& wall_cell);
  void CheckWest(Cell& wall_cell);
};