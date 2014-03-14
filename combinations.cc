// Copyright 2014 kevinew@leetcode Inc. All Rights Reserved.

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<vector<int> > combine(int n, int k) {
      vector<vector<int> > ans, cn_1k, cn_1k_1;

      if (n == k) {
        vector<int> cells;
        for (int i = 1; i <= n; ++i) {
          cells.push_back(i);
        }
        ans.push_back(cells);
        return ans;
      }

      if (k == 1) {
        for (int i = 1; i <= n; ++i) {
          vector<int> cells;
          cells.push_back(i);
          ans.push_back(cells);
        }
        return ans;
      }

      cout << "test 0";
      cn_1k = combine(n - 1, k);
      cn_1k_1 = combine(n - 1, k - 1);
      for (int i = 0; i < cn_1k_1.size(); ++i) {
        vector<int> line;
        // cn_1k_1[i].push_back(n);
        cout << "test 1";
        // cn_1k_1[i].insert(cn_1k_1[i].begin(), line.begin(), line.end());
        line.assign(cn_1k_1[i].begin(), cn_1k_1[i].end());
        line.push_back(n);
        ans.push_back(line);
        cout << "test 2";
      }
      ans.insert(ans.end(), cn_1k.begin(), cn_1k.end());

      return ans;
    }
};

int main(int argc, char **argv) {

  cout << "test a";
  Solution s;
  vector<vector<int> > result;
  result = s.combine(4, 2);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
