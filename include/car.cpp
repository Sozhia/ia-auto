/**
 * @file car.h
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * @email sozhia.business@gmail.com
 * @brief Car class and its definitions
 * @version 0.1
 * @date 2020-11-06
 */
#include "car.h"
/**
 * @brief Construct a new Car:: Car object
 * 
 */
Car::Car(){}
/**
 * @brief Construct a new Car:: Car object
 * 
 * @param x asign x value
 * @param y asign y value
 */
Car::Car(unsigned int x, unsigned int y) {
  pos_X_ = x;
  pos_Y_ = y;
}
/**
 * @brief Set Position X to object car
 * 
 * @param x_value  horizontal value in matrix
 */
void Car::SetPositionX(unsigned int x_value) {
  x_value = pos_X_;
}
/**
 * @brief Set Position Y to object car
 * 
 * @param y_value  horizontal value in matrix
 */
void Car::SetPositionY(unsigned int y_value) {
  y_value = pos_Y_;
}
/**
 * @brief Get Position X object
 * 
 */
unsigned int Car::GetPositionX() {
  return pos_X_;
}
/**
 * @brief Get the Position Y object
 * 
 */
unsigned int Car::GetPositionY() {
  return pos_Y_;
}
/**
 * @brief Destroy the Car object
 * 
 */
 Car::~Car() {
  pos_X_ = 0;
  pos_Y_ = 0;
  sum_cost_ = 0;
 }