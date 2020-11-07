/**
 * @file tile.cpp
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * @email sozhia.business@gmail.com
 * @brief Tile class and its definitions
 * @version 0.1
 * @date 2020-11-06
 */

#include "tile.h"

Tile::~Tile() {}

void Tile::SetCost(int value) {
  cost_ = value;
}
int Tile::GetCost() {
  return cost_;
}

void Tile::SetVisited(bool status) {
  visited_ = status;
}

bool Tile::GetVisited(){
  return visited_;
}

unsigned int Tile::GetPosX() {
  return x_pos_;
}
unsigned int Tile::GetPosY() {
  return y_pos_;
}
void Tile::FillTile(Cell& wall_cell, Cell& path_cell) {
  if (GetCost() != (std::numeric_limits<unsigned int>::max())) {
    for (unsigned int i = 0;i < 3; i++) {
      for (unsigned int j = 0; j < 3; j++){
        if ((i == 0 | i == 2) && (j == 0 | j == 2)) {
          cell_tile_[i][j] = wall_cell;
        }else{
          cell_tile_[i][j] = path_cell;
        }
      }
    }
  }else{
    for (unsigned int i = 0;i < 4; i++) {
      for (unsigned int j = 0; j < 4; j++){
        cell_tile_[i][j] = wall_cell;
      }
    }
  }
}

void Tile::CheckNorth(Cell& wall_cell) {
  for (unsigned foo1 = 0; foo1 < connected_.size(); foo1 ++) {
    if (connected_[foo1].GetPosY() == GetPosY() +1)
      cell_tile_[0][1] = wall_cell;
  }
}
void Tile::CheckSouth(Cell& wall_cell) {
  for (unsigned foo1 = 0; foo1 < connected_.size(); foo1 ++) {
    if (connected_[foo1].GetPosY() == GetPosY() -1)
      cell_tile_[2][1] = wall_cell;
  }
} 
void Tile::CheckEast(Cell& wall_cell) {
  for (unsigned foo1 = 0; foo1 < connected_.size(); foo1 ++) {
    if (connected_[foo1].GetPosX() == GetPosX() -1)
      cell_tile_[1][0] = wall_cell;
  }
} 
void Tile::CheckWest(Cell& wall_cell) {
  for (unsigned foo1 = 0; foo1 < connected_.size(); foo1 ++) {
    if (connected_[foo1].GetPosX() == GetPosX() +1)
      cell_tile_[1][2] = wall_cell;
  }
}
