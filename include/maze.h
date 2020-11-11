/**
 * @file maze.h
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * CONTACT: sozhia.business@gmail.com
 * @brief Tile class declaration
 * @version 1.0
 * @date 2020-11-11
 * COLLEGE: Universidad de la Laguna
 * DEGREE: Computer Science
 * SUBJECT: AI (I)
 * REFERENCE: https://github.com/Sozhia/ia-auto
 * 
 */

#include <vector>
#include "tile.cpp"
#include <time.h>
#include<cmath>
#include <limits>

class Maze {
 private:
  unsigned int rows_, columns_; // Maze size defined by rows_ x columns_
  unsigned int heuristic_; // Value of heuristic function used in A* pathfinding
  const int inf = std::numeric_limits<int>::max(); // inf: max value assigned to unreachable tiles
  std::vector<Tile> stack; // Stack used in DFS to generate realistic and based logic maze
  Tile** maze_matrix_; // Maze itself represented by matrix
 public:
  Maze();
  Maze(unsigned int a, unsigned int b);
  void SetRowSize(unsigned int rows);
  unsigned int GetRowSize();
  void SetColSize(unsigned int columns);
  unsigned int GetColSize();
  void SetHeuristic(Tile &start_tile, Tile &end_tile);
  unsigned int GetHeuristic();

  void DFS(Tile *start_tile);
  void FillMaze(Tile &start_tile, Tile &end_tile, Tile &wall_tile, Tile &path_tile, float percent_of_obstacles);
  void PrintMaze(Tile &start_tile, Tile &end_tile, Tile &wall_tile, Tile &path_tile);
  ~Maze();
};