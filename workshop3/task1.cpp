#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

vector<vector<int>> level_order(TreeNode *root) {
  vector<vector<int>> res;
  if (!root)
    return res;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int lsize = q.size();
    vector<int> level;

    for (int i = 0; i < lsize; i++) {
      TreeNode *node = q.front();
      q.pop();
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
      level.push_back(node->val);
    }
    res.push_back(level);
  }
  return res;
}

TreeNode *build_tree_from_array(const vector<int> &arr, int null_value = -1) {
  if (arr.empty() || arr[0] == null_value)
    return nullptr;

  int n = static_cast<int>(arr.size());
  TreeNode *root = new TreeNode(arr[0]);
  queue<TreeNode *> q;
  q.push(root);

  int i = 1;
  while (!q.empty() && i < n) {
    TreeNode *cur = q.front();
    q.pop();

    if (i < n && arr[i] != null_value) {
      cur->left = new TreeNode(arr[i]);
      q.push(cur->left);
    }
    i++;

    if (i < n && arr[i] != null_value) {
      cur->right = new TreeNode(arr[i]);
      q.push(cur->right);
    }
    i++;
  }

  return root;
}

void print_levels(const vector<vector<int>> &levels) {
  for (const auto &level : levels) {
    for (int value : level)
      cout << value << ' ';
    cout << '\n';
  }
}

void delete_tree(TreeNode *root) {
  if (!root)
    return;
  delete_tree(root->left);
  delete_tree(root->right);
  delete root;
}

int main() {
  vector<int> arr = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root = build_tree_from_array(arr);
  vector<vector<int>> levels = level_order(root);
  print_levels(levels);
  delete_tree(root);

  return 0;
}