/**
 * @file tile.h
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
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <limits>
#include <vector>

class Tile {
 private:
  unsigned int cost_;
  bool exit_ = false;
  bool start_ = false;
 public:
  Tile() {}
  Tile(unsigned int cost) {cost_ = cost;}
  void SetCost(unsigned int cost) {cost_ = cost;}
  unsigned int GetCost() {return cost_;}
  void SetExit() {exit_ = true;}
  void SetStart() {start_ = true;}
  bool GetExit() {return exit_;}
  bool GetStart() {return start_;}
  //bool operator == (const Tile& rh) const {return this==&rh;}
  //bool operator!= (const Tile &ptr) const {return !(this==&ptr);}
  ~Tile() {}
};