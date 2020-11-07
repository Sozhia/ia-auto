# Pathfinding A*

## 0.- Explanation
The autonomous vehicle test environment could be supossed as a `M x N` (free and non-free) tiles matrix. The supossed car moves should be done once at time, only adjacent ones (North, South, East and West) that are not ocuppied by an obstacle. 
Our car has a perception vector `[SN, SO, SS, SE]` to check that requirement.

## 1.- Maze Generator
The labyrinth is composed by a couple tiles, in turned composed by cells. We're gonna use DFS algorithm:
```console
Step 1: Insert the root tile or starting tile of a maze in the stack.
Step 2: Pop the top item from the stack and add it to the visited list.
Step 3: Find all the adjacent tiles of the tile marked visited and add the ones that are not yet visited, to the stack.
Step 4: Repeat steps 2 and 3 until the stack is empty.
```

## 2.- Pathfinding A*

