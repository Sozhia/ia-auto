/**
 * @file cell.h
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * @email sozhia.business@gmail.com
 * @brief Cell class and its definitions
 * @version 0.1
 * @date 2020-11-06
 */
#include <iostream>

class Cell {
 private:
  char symbol;
 public:
  Cell();
  ~Cell();
  char GetChar(Cell &cell);
  void SetChar(Cell &cell, char c);
};

