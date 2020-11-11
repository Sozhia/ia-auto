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

  Tile wall_tile;
  wall_tile.SetIdentifier(0);
  Tile start_tile;
  start_tile.SetIdentifier(1);
  Tile end_tile;
  end_tile.SetIdentifier(2);
  Tile path_tile;
  path_tile.SetIdentifier(3);
  Maze maze(20,20);
  
  
  maze.FillMaze(start_tile,end_tile,wall_tile, path_tile,10);
  maze.PrintMaze(start_tile,end_tile,wall_tile,path_tile);
  std::cout << "Valor heurisitca: " << maze.GetHeuristic() << std::endl;
}