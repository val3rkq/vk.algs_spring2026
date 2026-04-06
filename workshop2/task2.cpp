#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_less_equal(vector<vector<int>> &mtx, int x) {
  int n = mtx.size();
  int count = 0;
  int i = n - 1;
  int j = 0;

  while (i >= 0 && j < n) {
    if (mtx[i][j] <= x) {
      count += (i + 1);
      j++;
    } else {
      i--;
    }
  }
  return count;
}

int kth_smallest(vector<vector<int>> &mtx, int k) {
  int res = 0;
  int n = mtx.size();
  int l = mtx[0][0];
  int r = mtx[n - 1][n - 1];

  while (l <= r) {
    int m = l + (r - l) / 2;
    int count = count_less_equal(mtx, m);
    if (count < k) {
      l = m + 1;
    } else {
      r = m - 1;
      res = m;
    }
  }
  return res;
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  for (int k = 1; k < 10; k++) {
    cout << "k: " << k << ", kth smallest: " << kth_smallest(matrix, k) << endl;
  }
}