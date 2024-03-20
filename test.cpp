// boj 12100 simulation 복습
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int board[20][20], board2[20][20];

void rotate() {
  int tmp[20][20];
  for (int i=0;i<N;i++) 
    for (int j=0;j<N;j++)
      tmp[i][j] = board2[i][j];

  for (int i=0;i<N;i++) 
    for (int j=0;j<N;j++) 
      board2[i][j] = tmp[j][N-1-i];
    
}

void move(int dir) {
  while (dir--) rotate();

  for (int i=0;i<N;i++) {
    int idx = 0;
    int tmp[21] = {};
    for (int j=0;j<N;j++) {
      if (board2[i][j] == 0) continue;
      if (tmp[idx] == 0) tmp[idx] = board2[i][j];
      else if (tmp[idx] == board2[i][j]) tmp[idx++] += board2[i][j];
      else tmp[++idx] = board2[i][j];
    }
    for (int j=0;j<N;j++) 
      board2[i][j] = tmp[j];
  }
}

void sol() {
  int ans = 0;
  for (int i=0;i<1024;i++) {

    for (int r=0;r<N;r++)
      for (int c=0;c<N;c++) 
        board2[r][c] = board[r][c];

    int tmp = i;
    for (int j=0;j<5;j++) {
      int dir = tmp % 4;
      tmp /= 4;
      move(dir);
    }

    for (int r=0;r<N;r++)
      for (int c=0;c<N;c++) 
        ans = max(ans, board2[r][c]);
  }

  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      cin >> board[i][j];
    }
  }

  sol();
}