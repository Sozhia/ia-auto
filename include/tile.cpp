/**
 * @file tile.cpp
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

#include "tile.h"
/**
 * @brief Parameterized constructor of Tile class
 * 
 * @param identifier value of the identifier: {BLACK,BLUE,GREEN,WHITE,PURPLE} as {0,1,2,3,4} respectively
 */
Tile::Tile(unsigned int identifier) {
  identifier_ = identifier;
}
Tile::Tile(){}
/**
 * @brief Set the Identifier Attribute
 * 
 * @param value Value of the identifier_ attribute
 */
void Tile:: SetIdentifier(unsigned int value) {
  identifier_ = value;
}
/**
 * @brief Get value from identifier_ attribute
 * 
 * @return unsigned int attribute
 */
unsigned int Tile::GetIdentifier() {
  return identifier_;
}
/**
 * @brief Define operator ==
 * 
 * @param rh 
 * @return true if they are equal
 * @return false if they are not equal
 */
bool Tile::operator==(const Tile & rh) const {
  return this==&rh;
}
bool Tile::operator!= (const Tile &ptr) const {
  return !(this==&ptr);
}

Tile::~Tile(){}
