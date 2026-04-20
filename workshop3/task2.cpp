#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int k_largest_elem(vector<int> &arr, int k) {
  priority_queue<int, vector<int>, greater<int>> min_heap;

  for (int num : arr) {
    min_heap.push(num);
    if (min_heap.size() > k) {
      min_heap.pop();
    }
  }
  return min_heap.top();
}

int main() {
  vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  int k = 3;
  cout << k_largest_elem(arr, k) << endl;
  
  vector<int> sorted_arr = arr;
  sort(sorted_arr.begin(), sorted_arr.end(), greater<int>());
  cout << sorted_arr[k - 1] << endl;
  return 0;
}