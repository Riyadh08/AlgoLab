//All possible solution for 4 Queen problem

#include <bits/stdc++.h>
using namespace std;

const int N = 4;
vector<vector<vector<bool>> > solutions;

bool board[N][N];

bool isSafe(int row, int col) {
    // Check rows
    for (int k = 0; k < N; k++) {
        if (board[row][k] == true) return false;
    }

    // Check columns
    for (int k = 0; k < N; k++) {
        if (board[k][col] == true) return false;
    }

    // Check upper diagonal on left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == true) return false;
    }

    // Check lower diagonal on left
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == true) return false;
    }

    return true;
}

bool placeQueen(int col) {
    if (col == N) {
        vector<vector<bool>> solution;
        for (int i = 0; i < N; i++) {
            vector<bool> row;
            for (int j = 0; j < N; j++) {
                row.push_back(board[i][j]);
            }
            solution.push_back(row);
        }
        solutions.push_back(solution);
        return false; // Continue searching for more solutions
    }

    bool found = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = true;

            if (placeQueen(col + 1)) {
                found = true;
            }

            board[i][col] = false; // Backtrack
        }
    }

    return found;
}

int main() {
    placeQueen(0);

    if (solutions.empty()) {
        cout << "No solutions found." << endl;
    }
     else {
        cout << "Total solutions: " << solutions.size() << endl;
        for (int i = 0; i < solutions.size(); i++) {
            cout << "Solution " << i + 1 << ":\n";
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (solutions[i][j][k] == false) cout << ".";
                    else cout << "Q";
                }
                cout << endl;
            }
            cout << "\n";
        }
    }

    return 0;
}
