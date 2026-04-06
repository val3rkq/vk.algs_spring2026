#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longest_substring_length(string s) {
  int n = s.length();
  if (n == 0)
    return 0;

  int res = 0;
  int l = 0;
  vector<bool> visited(256, false);
  for (int r = 0; r < n; r++) {
    while (visited[s[r]]) {
      visited[s[l]] = false;
      l++;
    }
    visited[s[r]] = true;
    res = max(res, r - l + 1);
  }
  return res;
}

int main() {
  string s = "abcabcbb";
  cout << longest_substring_length(s) << endl; // 3

  string s2 = "aaaaaaa";
  cout << longest_substring_length(s2) << endl; // 1

  string s3 = "";
  cout << longest_substring_length(s3) << endl; // 0

  string s4 = "0123456789";
  cout << longest_substring_length(s4) << endl; // 10
}