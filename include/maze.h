/**
 * @file maze.h
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * @email sozhia.business@gmail.com
 * @brief Maze class and its definitions
 * @version 0.1
 * @date 2020-11-06
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include "tile.h"
#include <time.h>
#include<cmath>

class Maze{
 private:
 public:
  unsigned int rows_,columns_;
  unsigned int heuristic_;
  const int inf = std::numeric_limits<int>::max();
  std::vector<Tile> stack;
  std::vector<std::vector<Tile>>& maze_tile_;
  void SetRowSize(unsigned int rows);
  unsigned int GetRowSize();
  void SetColSize(unsigned int columns);
  unsigned int GetColSize();
  void FillMaze(Cell &wall_cell, Cell &path_cell);
  void SetHeuristic();
  unsigned int GetHeuristic();
  void DFS(Tile& tile);
  ~Maze();
};