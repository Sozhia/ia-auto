# Pathfinding A*

## 0.- Explanation
The autonomous vehicle test environment could be supossed as a `M x N` (free and non-free) tiles matrix. The supossed car moves should be done once at time, only adjacent ones (North, South, East and West) that are not ocuppied by an obstacle. 
Our car has a perception vector `[SN, SO, SS, SE]` to check that requirement.

## 1.- Maze Generator
The labyrinth is composed by a couple tiles, in turned composed by cells. We're gonna fill randomly using % of tiles.


## 2.- Pathfinding A*

