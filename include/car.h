#include <vector>
#include <bits/stdc++.h> 
#include <stack>
class Car {
 private:
  float path_cost_;
  std::vector<std::vector<bool>> visited_; //Map of visited Tiles
  unsigned int position_x_, position_y_;
  std::vector<std::pair<unsigned int, unsigned int> > stacked_pathfinding_;
 public:
 Car() {}
 unsigned int GetPosition() {return position_x_, position_y_;}
 void SetPosition(unsigned int a, unsigned int b) {position_x_ = a; position_y_ = b;}
 bool GetVisited(unsigned int column, unsigned int row) {return visited_[column][row];}
 void SetVisited(unsigned int column, unsigned int row) {visited_[column][row] = true;}
 void AddPathCost(float value) {path_cost_ += value;}
 float GetPathCost() {return path_cost_;}
 ~Car() {}
};