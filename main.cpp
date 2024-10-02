#include <iostream>
#include <string>

void Start();
void Game();
void printGrid();
void checkWin();
bool checkDraw();
void AiMove();
bool isGridEmpty();
bool playerOneMove = true;
bool endGame = false;

std::string grid[3][3] = {
    {" "," "," "},
    {" "," "," "},
    {" "," "," "}
};

void Game() {
    // if its not player one then its player two
    while (!endGame) {
        if (playerOneMove) {
            printGrid();
            //prints the grid in a grid format
            std::cout << "please enter the y first and x after of youre selected placement (1 - 3)" << std::endl;
            int i, j;
            std::cin >> i >> j;
            if (i < 1 || i > 3 || j < 1 || j > 3) {
                std::cout << "Invalid position! Please try again." << std::endl;
                continue;
            }

            // Check if the cell is occupied
            if (grid[i - 1][j - 1] != " ") {
                std::cout << "Cell is already occupied! Please try again." << std::endl;
                continue;
            }

            grid[i - 1][j - 1] = "X";

            checkWin();

            if (!endGame) { // Only switch turns if the game isn't over
                playerOneMove = !playerOneMove;
            }
        }
        else {
            AiMove();
        }
    }
}



bool isGridEmpty() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] != " ") {
                return false;
            }
        }
    }
    return true;
}

void checkWin() {
    // Check rows, columns, and diagonals for a winner
    for (int i = 0; i < 3; i++) {
        // Rows
        if (grid[i][0] == "X" && grid[i][1] == "X" && grid[i][2] == "X") {
            std::cout << "Player 1 (X) wins!" << std::endl;
            endGame = true;
            return; // Exit checkWin after announcing the winner
        }
        if (grid[i][0] == "O" && grid[i][1] == "O" && grid[i][2] == "O") {
            std::cout << "AI wins" << std::endl;
            endGame = true;
            return; // Exit checkWin after announcing the winner
        }
        // Columns
        if (grid[0][i] == "X" && grid[1][i] == "X" && grid[2][i] == "X") {
            std::cout << "Player 1 (X) wins!" << std::endl;
            endGame = true;
            return; // Exit checkWin after announcing the winner
        }
        if (grid[0][i] == "O" && grid[1][i] == "O" && grid[2][i] == "O") {
            std::cout << "AI wins" << std::endl;
            endGame = true;
            return; // Exit checkWin after announcing the winner
        }
    }

    // Diagonals
    if (grid[0][0] == "X" && grid[1][1] == "X" && grid[2][2] == "X") {
        std::cout << "Player 1 (X) wins!" << std::endl;
        endGame = true;
        return; // Exit checkWin after announcing the winner
    }
    if (grid[0][0] == "O" && grid[1][1] == "O" && grid[2][2] == "O") {
        std::cout << "AI wins" << std::endl;
        endGame = true;
        return; // Exit checkWin after announcing the winner
    }
    if (grid[0][2] == "X" && grid[1][1] == "X" && grid[2][0] == "X") {
        std::cout << "Player 1 (X) wins!" << std::endl;
        endGame = true;
        return; // Exit checkWin after announcing the winner
    }
    if (grid[0][2] == "O" && grid[1][1] == "O" && grid[2][0] == "O") {
        std::cout << "AI wins" << std::endl;
        endGame = true;
        return; // Exit checkWin after announcing the winner
    }

    // Check for draw
    if (checkDraw()) {
        endGame = true;
    }
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == " ") {
                return false; // There's still an empty cell
            }
        }
    }
    std::cout << "It's a draw!" << std::endl;
    return true; // The grid is full
}
void printGrid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << " " << grid[i][j];
            if (j < 2) {
                std::cout << " |";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "-----------" << std::endl;
        }
    }
    std::cout << std::endl;
}

void Start() {
    std::string input;
    std::cout << "Welcome to Tic tac toe, " << std::endl;
    std::cout << "Do you wanna play (y/n)" << std::endl;
    std::getline(std::cin, input);
    if (input == "y" || input == "Y") {
        Game();
    }
    else if (input == "n" || input == "N") {
        std::exit(0);
    }
}

int main() {
    do {
        // Check if the game has ended
        if (endGame) {
    
            std::cin.ignore(); // Clear any leftover newline
           
            // Reset the game state
            endGame = false; // Reset the end game flag
            // Reset the grid
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    grid[i][j] = " "; // Resetting the grid for a new game
                }
            }
        }
        Start();
    } while (true); // This loop continues until the program is exited.
    return 0;
}