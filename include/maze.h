/**
 * @file maze.h
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * CONTACT: sozhia.business@gmail.com
 * @brief Maze class declaration
 * @version 1.0
 * @date 2020-11-11
 * COLLEGE: Universidad de la Laguna
 * DEGREE: Computer Science
 * SUBJECT: AI (I)
 * REFERENCE: https://github.com/Sozhia/ia-auto
 * 
 */

#include "tile.h"
#include "car.h"
class Maze {
 private:
  unsigned int rows_, columns_; // Maze size defined by rows_ x columns_
  const int inf_ = std::numeric_limits<int>::max(); // inf: max value assigned to unreachable tiles
  Tile** maze_matrix_; // Maze itself represented by matrix
  float** heuristic_; // Heuristic of all values
 public:
  Maze();
  Maze(unsigned int a, unsigned int b);
  void SetRowSize(unsigned int rows);
  unsigned int GetRowSize();
  void SetColSize(unsigned int columns);
  unsigned int GetColSize();
  void SetHeuristic();
  float GetHeuristic(unsigned int pos1, unsigned int pos2);
  void SetUpMaze();
  void FillRandom(float percent_of_obstacles);
  bool Solve(unsigned int start_x, unsigned int start_y, Car &car);
  void PrintMaze(Car &car);
  ~Maze();
};