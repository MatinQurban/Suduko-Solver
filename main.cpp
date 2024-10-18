#include <iostream>
using namespace std;

const int N = 3;
const int BLANK = 0;

void printGrid(int grid[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool canUse(int grid[N][N], int move, int row, int col) {
  for (int i = 0; i < N; i++) {
    if (grid[row][i] == move || grid[i][col] == move) {
      return false;
    }
  }

  return true;
}

bool solveSudoku(int grid[N][N]) {
  int row, col;

  bool isEmpty = false;
  for (row = 0; row < N; row++) {
    for (col = 0; col < N; col++) {
      if (grid[row][col] == BLANK) {
        isEmpty = true;
        break;
      }
    }
    if (isEmpty) {
      break;
    }
  }

  if (!isEmpty) {
    return true;
  }

  for (int i = 1; i <= 3; i++) {
    if (canUse(grid, i, row, col)) {
      grid[row][col] = i;

      if (solveSudoku(grid)) {
        printGrid(grid);
      }

      grid[row][col] = BLANK;
    }
  }

  return false;
}

int main() {
  int board1[N][N] = {
  {BLANK, BLANK, BLANK}, 
  {BLANK, BLANK, BLANK}, 
  {BLANK, BLANK, BLANK}
};



  cout << "All solutions" << endl;
  solveSudoku(board1);
}