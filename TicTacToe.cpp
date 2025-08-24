#include <bits/stdc++.h>
using namespace std;

void printBoard(char board[3][3]) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2) cout << "---|---|---" << endl;
    }
    cout << endl;
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool isMovesLeft(char board[3][3]) {
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (board[r][c] != 'X' && board[r][c] != 'O')
                return true;
    return false;
}

void aiMove(char board[3][3], char ai, char human) {
    
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] != 'X' && board[r][c] != 'O') {
                char backup = board[r][c];
                board[r][c] = ai;
                if (checkWin(board, ai)) return; 
                board[r][c] = backup;
            }
        }
    }

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] != 'X' && board[r][c] != 'O') {
                char backup = board[r][c];
                board[r][c] = human;
                if (checkWin(board, human)) {
                    board[r][c] = ai;
                    return;
                }
                board[r][c] = backup;
            }
        }
    }

    //center
    if (board[1][1] != 'X' && board[1][1] != 'O') {
        board[1][1] = ai;
        return;
    }

    //corner
    pair<int, int> corners[] = {{0,0}, {0,2}, {2,0}, {2,2}};
    for (int i = 0; i < 4; i++) {
        int r = corners[i].first;
        int c = corners[i].second;
        if (board[r][c] != 'X' && board[r][c] != 'O') {
            board[r][c] = ai;
            return;
        }
    }

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] != 'X' && board[r][c] != 'O') {
                board[r][c] = ai;
                return;
            }
        }
    }
}

int main() {
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    char human = 'X';
    char ai = 'O';
    char winner = ' ';

    cout << "You are X, AI is O" << endl;

    for (int turn = 0; turn < 9 && winner == ' '; turn++) {
        printBoard(board);

        if (turn % 2 == 0) {
            int cell;
            while (true) {
                cout << "Enter a cell number (1-9): ";
                cin >> cell;
                if (cell < 1 || cell > 9) {
                    cout << "Invalid cell. Try again." << endl;
                    continue;
                }
                int r = (cell - 1) / 3;
                int c = (cell - 1) % 3;
                if (board[r][c] == 'X' || board[r][c] == 'O') {
                    cout << "Cell already taken. Try again." << endl;
                } else {
                    board[r][c] = human;
                    break;
                }
            }
            if (checkWin(board, human)) {
                winner = human;
                break;
            }
        } 
        else {
            aiMove(board, ai, human);
            if (checkWin(board, ai)) {
                winner = ai;
                break;
            }
        }
    }

    if (winner != ' ')
        cout << "Player " << winner << " wins!" << endl;
    else
        cout << "It's a tie!" << endl;

    return 0;
}
