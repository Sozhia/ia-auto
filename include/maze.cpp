/**
 * @file maze.cpp
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * CONTACT: sozhia.business@gmail.com
 * @brief Maze class definition
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
  maze_matrix_ = new Tile*[GetColSize()];
  for( unsigned int i = 0; i < GetColSize(); i++ )
    maze_matrix_[i] = new Tile[GetRowSize()];
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
void Maze::SetHeuristic() {
  float  tile_abscissa, tile_ordinate,  end_abscissa, end_ordinate, module;
  heuristic_ = new float*[GetColSize()];
  for( unsigned int i = 0; i < GetColSize(); i++ )
    heuristic_[i] = new float[GetRowSize()];
  for (unsigned int abscissa = 0; abscissa < rows_; abscissa ++) {
    for(unsigned int ordinate = 0; ordinate < columns_; ordinate ++) {
      if (maze_matrix_[abscissa][ordinate].GetExit()) {
        end_abscissa = abscissa;
        end_ordinate = ordinate;
      }
    }
  }
  for (unsigned int abscissa = 0; abscissa < rows_; abscissa ++) {
    for(unsigned int ordinate = 0; ordinate < columns_; ordinate ++) {
      if (maze_matrix_[abscissa][ordinate].GetCost() != inf_) {
        if (!maze_matrix_[abscissa][ordinate].GetExit()) {
          tile_abscissa = abscissa;
          tile_ordinate = ordinate;
          module = sqrt(( tile_abscissa -  end_abscissa) * ( tile_abscissa -  end_abscissa ) 
                  + (tile_ordinate - end_ordinate) * (tile_ordinate - end_ordinate));
          heuristic_[abscissa][ordinate] = module;
        }
      } else {
        heuristic_[abscissa][ordinate] = inf_;
      } 
    }
  }
}
/**
 * @brief Get the Heuristic Attribute value 
 * 
 * @return float heuristic_ value
 */
float Maze::GetHeuristic(unsigned int pos1, unsigned int pos2) {
  return heuristic_[pos1][pos2];
}
/**
 * @brief Fill Matrix with Cost = 1 by default
 * 
 * @param start_tile Start point
 * @param end_tile End point or goal
 * @param percent_of_obstacles % of obstacles
 */
void Maze::SetUpMaze() {
  srand((unsigned int)time(NULL));
  for (unsigned int i = 0; i < GetRowSize(); i++) {  
    for (unsigned int j = 0; j < GetColSize(); j++) {
      Tile tile;
      maze_matrix_[i][j] = tile;
      maze_matrix_[i][j].SetCost(1);
    }
  }
  // SET RANDOMLY START AND EXIT
  unsigned int pos_1 = rand()%GetColSize();
  unsigned int pos_2 = rand()%GetRowSize();
  maze_matrix_[pos_1][pos_2].SetStart();
  bool flag = false;
  do {
    unsigned int pos_3 = rand()%GetColSize();
    unsigned int pos_4 = rand()%GetRowSize();
    if (!maze_matrix_[pos_3][pos_4].GetStart()) {
      maze_matrix_[pos_3][pos_4].SetExit();
      flag = true;
    }  
  } while (!flag);
}
/**
 * @brief Fill Randomly with % of obstacles
 * 
 * @param percent_of_obstacles 
 */
void Maze::FillRandom(float percent_of_obstacles) {
  unsigned int space = (GetRowSize() * GetColSize()); // GETTING MAZE AREA
  unsigned int temp = space * (percent_of_obstacles/100); // SETTING % OF THAT AREA
  unsigned int count = 0;
  do {
    unsigned int v1 = rand() % GetColSize();
    unsigned int v2 = rand() % GetRowSize();
    if (maze_matrix_[v1][v2].GetCost() != inf_ && !(maze_matrix_[v1][v2].GetStart() || maze_matrix_[v1][v2].GetExit())) {
      maze_matrix_[v1][v2].SetCost(inf_);
      count ++;
    }
  }while (count < temp);
}

bool Maze::Solve(unsigned int start_x, unsigned int start_y, Car &car) {
  if (maze_matrix_[start_x][start_y].GetExit()) {
    car.SetVisited(start_x,start_y);
    return true;
  }
  if () {
    
  }


}

/**
 * @brief 
 * 
 * @param start_tile 
 * @param end_tile 
 * @param wall_tile 
 */
void Maze::PrintMaze(Car &car) {
  for (unsigned int aux1 = 0; aux1 < rows_; aux1 ++) {
    for(unsigned int aux2 = 0; aux2 < columns_; aux2 ++) {
      if (car.GetVisited(aux1, aux2)) {
        std::cout << "[º]";
      } else if (maze_matrix_[aux1][aux2].GetExit()) {
        std::cout << "[E]";
      } else if (maze_matrix_[aux1][aux2].GetStart()) {
        std::cout << "[S]";
      }else if (maze_matrix_[aux1][aux2].GetCost() == 1) {
        std::cout << "[ ]";
      } else if (maze_matrix_[aux1][aux2].GetCost() == inf_) {
        std::cout << "[#]";
      } 
    }
    std::cout << std::endl;
  }
}

//void Maze::DFS(Tile& tile) {}
Maze::~Maze(){}


