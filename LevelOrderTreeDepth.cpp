int LevelOrderTree(TreeNode *root) {
  if (root == NULL)
    return 0;
  queue<TreeNode *> q;
  q.push(root);
  int cnt = 1, nextcnt = 0, cur = 0, depth = 0;
  while (!q.empty()) {
    root = q.front();
    cur++;
    if (root->left) {
      q.push(root->left);
      nextcnt++;
    }
    if (root->right) {
      q.push(root->right);
      nextcnt++;
    }
    if (cur == cnt) {
      depth++;
      cnt = nextcnt;
      nextcnt = 0;
      cur = 0;
    }
    q.pop();
  }
  return depth;
}
