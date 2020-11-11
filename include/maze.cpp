/**
 * @file maze.cpp
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * CONTACT: sozhia.business@gmail.com
 * @brief Tile class definition
 * @version 1.0
 * @date 2020-11-11
 * COLLEGE: Universidad de la Laguna
 * DEGREE: Computer Science
 * SUBJECT: AI (I)
 * REFERENCE: https://github.com/Sozhia/ia-auto
 * 
 */
#include "maze.h"
Maze::Maze() {}
Maze::Maze(unsigned int a, unsigned int b) {
  SetColSize(b);
  SetRowSize(a);
  maze_matrix_ = new Tile*[GetRowSize()];
  for( unsigned int i = 0; i < GetRowSize(); i++ )
    maze_matrix_[i] = new Tile[GetColSize()];
  
}
/**
 * @brief Set the Row Size Attribute (rows_)
 * 
 * @param rows number of rows
 */
void Maze::SetRowSize(unsigned int rows) {
  rows_ = rows;
}
/**
 * @brief Get the Row Size Attribute value
 * 
 * @return unsigned int attribute value
 */
unsigned int Maze::GetRowSize() {
  return rows_;
}
/**
 * @brief Set the Column Size Attribute (columns_)
 * 
 * @param rows number of columns_
 */
void Maze::SetColSize(unsigned int columns) {
  columns_ = columns;
}
/**
 * @brief Get the columns Size Attribute value
 * 
 * @return unsigned int attribute value
 */
unsigned int Maze::GetColSize() {
  return columns_;
}
/**
 * @brief Set the Heuristic Attribute value using The Pythagorean Theorem
 * 
 * @param start_tile start position in maze
 * @param end_tile end position in maze
 */
void Maze::SetHeuristic(Tile &start_tile, Tile &end_tile) {
  float  start_abscissa, start_ordinate,  end_abscissa, end_ordinate, module;
  for (unsigned int abscissa = 0; abscissa < rows_; abscissa ++) {
    for(unsigned int ordinate = 0; ordinate < columns_; ordinate ++) {
      if (maze_matrix_[abscissa][ordinate] == start_tile) {
        start_abscissa = abscissa;
        start_ordinate = ordinate;
      }
      if (maze_matrix_[abscissa][ordinate] == end_tile) {
        end_abscissa = abscissa;
        end_ordinate = ordinate;
      }
    }
  }
  module = sqrt(( start_abscissa -  end_abscissa) * ( start_abscissa -  end_abscissa ) 
                  + (start_ordinate - end_ordinate) * (start_ordinate - end_ordinate));
  heuristic_ = static_cast<unsigned int>(module);
}
/**
 * @brief Get the Heuristic Attribute value 
 * 
 * @return unsigned int heuristic_ value
 */
unsigned int Maze::GetHeuristic() {
  return heuristic_;
}
/**
 * @brief Randomly fill with obstacles maze_matrix_ matrix of Tiles*
 * 
 * @param start_tile Start point
 * @param end_tile End point or goal
 * @param percent_of_obstacles % of obstacles
 */
void Maze::FillMaze(Tile &start_tile, Tile &end_tile, Tile &wall_tile, Tile &path_tile, float percent_of_obstacles) {
  for (unsigned int i = 0; i < GetRowSize(); i++) {  
    for (unsigned int j = 0; j < GetColSize(); j++) {  
      if (i == 0 || i == GetRowSize()-1 || j == 0 || j == GetColSize()-1) {      
        maze_matrix_[i][j] = wall_tile;    
      } else {
        maze_matrix_[i][j] = path_tile;
      }
    }
  }
  maze_matrix_[1][1] = start_tile;
  maze_matrix_[4][4] = end_tile; 
}

/**
 * @brief 
 * 
 * @param start_tile 
 * @param end_tile 
 * @param wall_tile 
 */
void Maze::PrintMaze(Tile &start_tile, Tile &end_tile, Tile &wall_tile, Tile &path_tile) {
  for (unsigned int aux1 = 0; aux1 < rows_; aux1 ++) {
    for(unsigned int aux2 = 0; aux2 < columns_; aux2 ++) {
      if (maze_matrix_[aux1][aux2].GetIdentifier() == 0) {
        std::cout << "X";
      } else if (maze_matrix_[aux1][aux2].GetIdentifier() == 2) {
        std::cout << "E";
      } else if (maze_matrix_[aux1][aux2].GetIdentifier() == 1) {
        std::cout << "S";
      } else if (maze_matrix_[aux1][aux2].GetIdentifier() == 3) {
        std::cout << char(177);
      } 
    }
    std::cout << std::endl;
  }
}

//void Maze::DFS(Tile& tile) {}
Maze::~Maze(){}


