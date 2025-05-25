#include <iostream>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <cmath>   // for exp()

const int BOARD_SIZE = 8;

// Function to initialize the board with random queen placements
void initializeBoard(std::vector<int>& board) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[i] = rand() % BOARD_SIZE; // Place each queen in a random column of its row
    }
}

// Function to print the board
void printBoard(const std::vector<int>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (j == board[i]) {
                std::cout << "Q ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Function to check if a queen threatens another queen
bool isThreatened(const std::vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col ||            // Check column
            board[i] - i == col - row ||  // Check diagonal (left upper)
            board[i] + i == col + row) { // Check diagonal (right upper)
            return true;
        }
    }
    return false;
}

// Function to count the number of threatened queens
int countThreatenedQueens(const std::vector<int>& board) {
    int count = 0;
    for (int i = 1; i < BOARD_SIZE; ++i) {
        if (isThreatened(board, i, board[i])) {
            count++;
        }
    }
    return count;
}

// Function to calculate the cost of the board
double calculateCost(const std::vector<int>& board) {
    return countThreatenedQueens(board);
}

// Function to perform simulated annealing
void simulatedAnnealing(std::vector<int>& board, double initialTemperature, double coolingRate) {
    double currentTemperature = initialTemperature;

    while (currentTemperature > 0.1) {
        // Choose a random queen and move it to a random column
        int queenIndex = rand() % BOARD_SIZE;
        int originalCol = board[queenIndex];
        int newCol = rand() % BOARD_SIZE;
        board[queenIndex] = newCol;

        // Calculate the cost of the new state
        double currentCost = calculateCost(board);

        // Calculate the change in cost
        int deltaCost = currentCost - calculateCost(board);

        // If the move improves the solution, keep it
        // If not, accept the move with a probability based on the current temperature
        if (deltaCost > 0 || exp(-deltaCost / currentTemperature) > static_cast<double>(rand()) / RAND_MAX) {
            board[queenIndex] = newCol;
        } else {
            board[queenIndex] = originalCol;
        }

        // Cool down the temperature
        currentTemperature *= coolingRate;
    }
}

int main() {
    std::vector<int> board(BOARD_SIZE);
    
    // Initialize the board with random queen placements
    initializeBoard(board);
    
    // Print the initial board
    std::cout << "Initial board:" << std::endl;
    printBoard(board);
    
    // Set initial temperature and cooling rate
    double initialTemperature = 100.0;
    double coolingRate = 0.95;
    
    // Solve using simulated annealing
    simulatedAnnealing(board, initialTemperature, coolingRate);
    
    // Print the final conflict-free board
    std::cout << "Final conflict-free board:" << std::endl;
    printBoard(board);

    return 0;
}
