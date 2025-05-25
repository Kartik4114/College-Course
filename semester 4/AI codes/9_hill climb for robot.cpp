#include <iostream>
#include <vector>
#include <cmath>

// Define the grid size
const int GRID_SIZE = 5;

// Define the goal position
const int GOAL_ROW = 4;
const int GOAL_COL = 4;

// Define the starting position
const int START_ROW = 0;
const int START_COL = 0;

// Define the movements: up, down, left, right
const int MOVES[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Function to check if a position is within the grid
bool isValid(int row, int col) {
    return (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE);
}

// Simple Hill Climbing algorithm to find the optimal path
void simpleHillClimbing() {
    // Initialize the current position to the starting position
    int currentRow = START_ROW;
    int currentCol = START_COL;

    // Loop until the goal is reached or no better move is possible
    while (currentRow != GOAL_ROW || currentCol != GOAL_COL) {
        // Initialize the best move to the current position
        int bestRow = currentRow;
        int bestCol = currentCol;
        int minDistance = std::abs(GOAL_ROW - currentRow) + std::abs(GOAL_COL - currentCol);

        // Check all possible moves
        for (int i = 0; i < 4; ++i) {
            int newRow = currentRow + MOVES[i][0];
            int newCol = currentCol + MOVES[i][1];

            // Check if the new position is valid
            if (isValid(newRow, newCol)) {
                // Calculate the distance to the goal from the new position
                int distance = std::abs(GOAL_ROW - newRow) + std::abs(GOAL_COL - newCol);

                // Update the best move if it reduces the distance to the goal
                if (distance < minDistance) {
                    bestRow = newRow;
                    bestCol = newCol;
                    minDistance = distance;
                }
            }
        }

        // If no better move is found, break the loop
        if (bestRow == currentRow && bestCol == currentCol) {
            break;
        }

        // Move to the best position
        currentRow = bestRow;
        currentCol = bestCol;
    }

    // Print the path
    std::cout << "Optimal path: (" << START_ROW << ", " << START_COL << ")";
    std::cout << " -> (" << currentRow << ", " << currentCol << ")" << std::endl;
}

int main() {
    // Call the Simple Hill Climbing algorithm to find the optimal path
    simpleHillClimbing();

    return 0;
}
