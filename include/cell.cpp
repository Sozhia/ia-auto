/**
 * @file cell.cpp
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * @email sozhia.business@gmail.com
 * @brief Cell class and its definitions
 * @version 0.1
 * @date 2020-11-06
 */

#include "cell.h"

char Cell::GetChar(Cell &cell) {
  return cell.symbol;
}
void Cell::SetChar(Cell &cell, char c) {
  cell.symbol = c;
}
