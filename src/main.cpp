/**
 * @file main.cpp
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * CONTACT: sozhia.business@gmail.com
 * @brief Main function
 * @version 1.0
 * @date 2020-11-11
 * COLLEGE: Universidad de la Laguna
 * DEGREE: Computer Science
 * SUBJECT: AI (I)
 * REFERENCE: https://github.com/Sozhia/ia-auto
 * 
 */

#include "../include/maze.cpp"

int main(int argc, char** argv) {
  Maze maze(11,11);
  Car car;
  maze.SetUpMaze();
  maze.FillRandom(10);
  maze.SetHeuristic();
  maze.PrintMaze(car);
  /**
  for (unsigned int i = 0; i < maze.GetColSize(); i++) {
    for (unsigned int j = 0; j < maze.GetRowSize(); j++) {
      std::cout << "Columna: " << i << " Fila: " << j << std::endl;
      std::cout << maze.GetHeuristic(i,j) << std::endl;
    }
    std::cout << std::endl;
  }
  **/
}