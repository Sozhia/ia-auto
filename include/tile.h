/**
 * @file tile.H
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
#include <cstdlib>

class Tile {
 private:
  unsigned int identifier_;
 public:
  Tile();
  Tile(unsigned int identifier);
  void SetIdentifier(unsigned int value);
  unsigned int GetIdentifier();
  bool operator == (const Tile& rh)const;
  bool operator!= (const Tile &ptr) const;
  ~Tile();
};