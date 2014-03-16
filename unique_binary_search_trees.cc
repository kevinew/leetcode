// 左右两边分个数进行递归
class Solution {
  public:
    int numTrees(int n) {
      if (0 == n || 1 == n) return 1;
      int ret = 0;
      for (int i = 0; i < n; ++i) ret += numTrees(i) * numTrees(n -1 - i);

      return ret;
    }
};
