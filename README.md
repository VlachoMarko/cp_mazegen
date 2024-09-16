## Maze Generator and Path Finder
This project generates random mazes using the **Recursive Backtracker Algorithm** and finds a path from the top-left corner to the bottom-right corner. It was developed as part of the **Computer Programming** course at **Vrije Universiteit Amsterdam**.

## Features
- Random Maze Generation: Generates a maze of customizable size with walls and cells using a recursive backtracking algorithm.
- Pathfinding: Finds a path from the start (top-left corner) to the end (bottom-right corner) using recursive backtracking, ensuring there are no detours.
- Command-line Parameters: Takes two or three command-line arguments:
  - The number of rows.
  - The number of columns.
- An optional seed value for random maze generation.
- Precise Maze Output: Prints the maze and the found path in a specific format to ensure consistency.

# Key Concepts
- Recursive Backtracking: Used for both maze generation and pathfinding.
- Classes: Implements well-structured classes to manage the maze, cells, and coordinates.
- Error Handling: Uses exceptions to handle invalid input or errors during execution.
