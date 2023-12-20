#include <stdio.h>

// Function to display the Tic Tac Toe game board
void GameBoard(char board[4][4]) {
    printf("\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf(" %c ", board[i][j]);
            if (j < 3) printf("|");
        }
        printf("\n");
        if (i < 3) printf("---------------\n");
    }
    printf("\n");
}

// Function to check if a player won
int winner(char board[4][4], char player) {
    // Check rows and columns
    for (int i = 0; i < 4; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][3] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player)) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player) ||
        (board[0][3] == player && board[1][2] == player && board[2][1] == player && board[3][0] == player)) {
        return 1; 
    }

    return 0; // No win yet
}

int main() {
    char board[4][4] = {{' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' '}};

    char player1 = 'X';
    char player2 = 'O';
    char current_player = player1;
    int row, col;

    GameBoard(board);

    for (int move = 1; move <= 16; move++) {
        printf("Player %d's turn\n", (current_player == player1) ? 1 : 2);

        // Get user input for row and column
        do {
            printf("Enter row (1-4): ");
            scanf("%d", &row);
            printf("Enter column (1-4): ");
            scanf("%d", &col);

            // Convert to 0-based index
            row--;
            col--;

            // Check if the input is valid
            if (row < 0 || row >= 4 || col < 0 || col >= 4 || board[row][col] != ' ') {
                printf("Spot is taken. Try again.\n");
            }

        } while (row < 0 || row >= 4 || col < 0 || col >= 4 || board[row][col] != ' ');

        // Make the move
        board[row][col] = current_player;

        GameBoard(board);

        // Check for a win
        if (winner(board, current_player)) {
            printf("Player %d wins!\n", (current_player == player1) ? 1 : 2);
            return 0;
        }

        // Switch player for the next turn
        current_player = (current_player == player1) ? player2 : player1;
    }

    // If no player wins after 16 moves
    printf("No one wins!\n");

    return 0;
}
