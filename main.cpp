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
            while (true) {
                std::cin >> i >> j;
                if (std::cin.fail() || i < 1 || i > 3 || j < 1 || j > 3) {
                    std::cout << "Invalid input! Please enter two numbers between 1 and 3." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }else if (i < 1 || i > 3 || j < 1 || j > 3) {
                    std::cout << "Invalid position! Please try again." << std::endl;
                    continue;
                }else   if (grid[i - 1][j - 1] != " ") {
                        std::cout << "Cell is already occupied! Please try again." << std::endl;
                        continue;
                    }
                else {
                    break; // Valid input
                }
            }
           

          

            grid[i - 1][j - 1] = "X";

            checkWin();

            if (!endGame) { // Only switch turns if the game isn't over
                playerOneMove = !playerOneMove;
            }
        }
        else {
            AiMove();
            checkWin();
        }
    }
}

void AiMove() {
    bool isEmpty = isGridEmpty();
    if (!isEmpty) {
        // Checking for potential blocking moves
        for (int i = 0; i < 3; i++) {
            // Check for AI winning moves with "0"
            // Rows
            for (int j = 0; j < 3; j++) {
                if (grid[i][0] == "0" && grid[i][1] == "0" && grid[i][2] == " ") {
                    grid[i][2] = "0";  // Use assignment operator
                    playerOneMove = !playerOneMove;
                    return;
                }
                else if (grid[i][0] == " " && grid[i][1] == "0" && grid[i][2] == "0") {
                    grid[i][0] = "0";  // Use assignment operator
                    playerOneMove = !playerOneMove;
                    return;
                }
                else if (grid[i][0] == "0" && grid[i][1] == " " && grid[i][2] == "0") {
                    grid[i][1] = "0";  // Use assignment operator
                    playerOneMove = !playerOneMove;
                    return;
                }
            }

            // Columns
            for (int j = 0; j < 3; j++) {
                if (grid[0][j] == "0" && grid[1][j] == "0" && grid[2][j] == " ") {
                    grid[2][j] = "0";  // Use assignment operator
                    playerOneMove = !playerOneMove;
                    return;
                }
                else if (grid[0][j] == " " && grid[1][j] == "0" && grid[2][j] == "0") {
                    grid[0][j] = "0";  // Use assignment operator
                    playerOneMove = !playerOneMove;
                    return;
                }
                else if (grid[0][j] == "0" && grid[1][j] == " " && grid[2][j] == "0") {
                    grid[1][j] = "0";  // Use assignment operator
                    playerOneMove = !playerOneMove;
                    return;
                }
            }

            // Diagonals for "0"
            if (grid[0][0] == "0" && grid[1][1] == "0" && grid[2][2] == " ") {
                grid[2][2] = "0";  // Use assignment operator
                playerOneMove = !playerOneMove;
                return;
            }
            else if (grid[0][0] == " " && grid[1][1] == "0" && grid[2][2] == "0") {
                grid[0][0] = "0";  // Use assignment operator
                playerOneMove = !playerOneMove;
                return;
            }
            else if (grid[0][0] == "0" && grid[1][1] == " " && grid[2][2] == "0") {
                grid[1][1] = "0";  // Use assignment operator
                playerOneMove = !playerOneMove;
                return;
            }
            // Rows for blocking "X"
            if (grid[i][0] == "X" && grid[i][1] == "X" && grid[i][2] == " ") {
                grid[i][2] = "0";  // Use assignment operator
                playerOneMove = !playerOneMove;
                return;
            }
            else if (grid[i][0] == " " && grid[i][1] == "X" && grid[i][2] == "X") {
                grid[i][0] = "0";  // Use assignment operator
                playerOneMove = !playerOneMove;
                return;
            }
            else if (grid[i][0] == "X" && grid[i][1] == " " && grid[i][2] == "X") {
                grid[i][1] = "0";  // Use assignment operator
                playerOneMove = !playerOneMove;
                return;
            }
        }

        // Columns for blocking "X"
        for (int j = 0; j < 3; j++) {
            if (grid[0][j] == "X" && grid[1][j] == "X" && grid[2][j] == " ") {
                grid[2][j] = "0";  // Use assignment operator
                playerOneMove = !playerOneMove;
                return;
            }
            else if (grid[0][j] == " " && grid[1][j] == "X" && grid[2][j] == "X") {
                grid[0][j] = "0";  // Use assignment operator
                playerOneMove = !playerOneMove;
                return;
            }
            else if (grid[0][j] == "X" && grid[1][j] == " " && grid[2][j] == "X") {
                grid[1][j] = "0";  // Use assignment operator
                playerOneMove = !playerOneMove;
                return;
            }
        }

        // Diagonals for blocking "X"
        if (grid[0][0] == "X" && grid[1][1] == "X" && grid[2][2] == " ") {
            grid[2][2] = "0";  // Use assignment operator
            playerOneMove = !playerOneMove;
            return;
        }
        else if (grid[0][0] == " " && grid[1][1] == "X" && grid[2][2] == "X") {
            grid[0][0] = "0";  // Use assignment operator
            playerOneMove = !playerOneMove;
            return;
        }
        else if (grid[0][0] == "X" && grid[1][1] == " " && grid[2][2] == "X") {
            grid[1][1] = "0";  // Use assignment operator
            playerOneMove = !playerOneMove;
            return;
        }

        // Second diagonal for blocking "X"
        if (grid[0][2] == "X" && grid[1][1] == "X" && grid[2][0] == " ") {
            grid[2][0] = "0";  // Use assignment operator
            playerOneMove = !playerOneMove;
            return;
        }
        else if (grid[0][2] == " " && grid[1][1] == "X" && grid[2][0] == "X") {
            grid[0][2] = "0";  // Use assignment operator
            playerOneMove = !playerOneMove;
            return;
        }
        else if (grid[0][2] == "X" && grid[1][1] == " " && grid[2][0] == "X") {
            grid[1][1] = "0";  // Use assignment operator
            playerOneMove = !playerOneMove;
            return;
        }

        // AI strategy for placing "0"
        if (grid[0][0] == "X" && grid[2][2] == " ") {
            grid[2][2] = "0"; // Place "0" at bottom-right if top-left is "0"
            playerOneMove = !playerOneMove; // Switch player
            return; // Exit after making a move
        }
        if (grid[0][2] == "X" && grid[2][0] == " ") {
            grid[2][0] = "0"; // Place "0" at bottom-left if top-right is "0"
            playerOneMove = !playerOneMove; // Switch player
            return; // Exit after making a move
        }
        if (grid[2][0] == "X" && grid[0][2] == " ") {
            grid[0][2] = "0"; // Place "0" at top-right if bottom-left is empty
            playerOneMove = !playerOneMove; // Switch player
            return; // Exit after making a move
        }
        if (grid[2][2] == "X" && grid[0][0] == " ") {
            grid[0][0] = "0"; // Place "0" at top-left if bottom-right is "0"
            playerOneMove = !playerOneMove; // Switch player
            return; // Exit after making a move
        }

        // Fallback strategies
        if (grid[1][1] == " ") {
            grid[1][1] = "0";
        }
        else if (grid[0][0] == " ") {
            grid[0][0] = "0";
        }
        else if (grid[0][2] == " ") {
            grid[0][2] = "0";
        }
        else if (grid[2][0] == " ") {
            grid[2][0] = "0";
        }
        else if (grid[2][2] == " ") {
            grid[2][2] = "0";
        }
        else if (grid[0][1] == " ") {
            grid[0][1] = "0";
        }
        else if (grid[1][0] == " ") {
            grid[1][0] = "0";
        }
        else if (grid[1][2] == " ") {
            grid[1][2] = "0";
        }
        else if (grid[2][1] == " ") {
            grid[2][1] = "0";
        }

        // Switch turns
        playerOneMove = !playerOneMove;
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
            printGrid();
            std::cout << "Player 1 (X) wins!" << std::endl;
            endGame = true;
            return; // Exit checkWin after announcing the winner
        }
        if (grid[i][0] == "0" && grid[i][1] == "0" && grid[i][2] == "0") {
            printGrid();
            std::cout << "AI wins" << std::endl;
            endGame = true;
            return; // Exit checkWin after announcing the winner
        }
        // Columns
        if (grid[0][i] == "X" && grid[1][i] == "X" && grid[2][i] == "X") {
            printGrid();
            std::cout << "Player 1 (X) wins!" << std::endl;
            endGame = true;
            return; // Exit checkWin after announcing the winner
        }
        if (grid[0][i] == "0" && grid[1][i] == "0" && grid[2][i] == "0") {
            printGrid();
            std::cout << "AI wins" << std::endl;
            endGame = true;
            return; // Exit checkWin after announcing the winner
        }
    }

    // Diagonals
    if (grid[0][0] == "X" && grid[1][1] == "X" && grid[2][2] == "X") {
        printGrid();
        std::cout << "Player 1 (X) wins!" << std::endl;
        endGame = true;
        return; // Exit checkWin after announcing the winner
    }
    if (grid[0][0] == "0" && grid[1][1] == "0" && grid[2][2] == "0") {
        printGrid();
        std::cout << "AI wins" << std::endl;
        endGame = true;
        return; // Exit checkWin after announcing the winner
    }
    if (grid[0][2] == "X" && grid[1][1] == "X" && grid[2][0] == "X") {
        printGrid();
        std::cout << "Player 1 (X) wins!" << std::endl;
        endGame = true;
        return; // Exit checkWin after announcing the winner
    }
    if (grid[0][2] == "0" && grid[1][1] == "0" && grid[2][0] == "0") {
        printGrid();
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
    printGrid();
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
    endGame = false; // Initialize endGame at the start
    do {
        if (endGame) {
            std::cin.ignore();
            endGame = false; // Reset the end game flag
            playerOneMove = true;

            // Reset the grid
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    grid[i][j] = " ";
                }
            }
        }
        Start();
    } while (true);
}
