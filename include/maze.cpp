/**
 * @file maze.cpp
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * @email sozhia.business@gmail.com
 * @brief Maze class and its definitions
 * @version 0.1
 * @date 2020-11-06
 */
#include "maze.h"
/**
 * @brief Construct a new Maze:: Maze object
 * 
 */
void Maze::SetRowSize(unsigned int rows) {
  rows_ = rows;
}
unsigned int Maze::GetRowSize() {
  return rows_;
}
void Maze::SetColSize(unsigned int columns){
  columns_ = columns;
}
unsigned int Maze::GetColSize() {
  return columns_;
}
void Maze::FillMaze(Cell &wall_cell, Cell &path_cell) {
  for (unsigned int n = 0; n < GetRowSize(); n++ ) {
    for (unsigned int m = 0; m < GetColSize(); m++ ) {
      Tile tile;
      if (n == 0 || n == GetRowSize() || m == 0 || m == GetColSize())
        tile.SetCost(inf);
      tile.FillTile(wall_cell, path_cell);
      maze_tile_[n].push_back(tile);
    }
  }
  unsigned int count = 0;
  do {
    unsigned int randoma = rand() % (maze_tile_.size());
    unsigned int randomb = rand() % (maze_tile_.size());
    if (count != 0)
      maze_tile_[randoma][randomb].SetExit();
    if (count == 0)
      maze_tile_[randoma][randomb].SetEntrance();
    count ++;
  }while(count < 2);
}
void Maze::SetHeuristic() {
  /*
  if (rows_ > 0 && columns_ > 0) { 
    heuristic_ = (unsigned int) sqrt(pow(rows_,2)+ pow(columns_,2));
  }
  */
  heuristic_ = 1;
}
void Maze::DFS(Tile& tile){
  do{
    tile.neighbours_.clear();
    stack.back().SetVisited(true);
    if (maze_tile_[tile.GetPosX() +1][tile.GetPosY()].GetVisited() != true) {
      if (maze_tile_[tile.GetPosX() +1][tile.GetPosY()].GetCost() != inf) {
        tile.neighbours_.push_back(maze_tile_[tile.GetPosX() +1][tile.GetPosY()]);
      }
    }
    if (maze_tile_[tile.GetPosX() -1][tile.GetPosY()].GetVisited() != true) {
      if (maze_tile_[tile.GetPosX() -1][tile.GetPosY()].GetCost() != inf) {
        tile.neighbours_.push_back(maze_tile_[tile.GetPosX() -1][tile.GetPosY()]);
      }
    }
    if (maze_tile_[tile.GetPosX()][tile.GetPosY() +1].GetVisited() != true) {
      if (maze_tile_[tile.GetPosX()][tile.GetPosY() +1].GetCost() != inf) {
        tile.neighbours_.push_back(maze_tile_[tile.GetPosX()][tile.GetPosY()+1]);
      }
    }
    if (maze_tile_[tile.GetPosX()][tile.GetPosY() -1].GetVisited() != true) {
      if (maze_tile_[tile.GetPosX()][tile.GetPosY() -1].GetCost() != inf) {
        tile.neighbours_.push_back(maze_tile_[tile.GetPosX()][tile.GetPosY()-1]);
      }
    }
    if (tile.neighbours_.empty()) {
      stack.pop_back();
    }else{
      unsigned int random = rand() % (tile.neighbours_.size());
      tile.connected_.push_back(tile.neighbours_[random]);
      stack.push_back(tile.neighbours_[random]);
      DFS(tile.connected_.back());
    }
  }while(stack.empty() != true);
}
Maze::~Maze(){}


