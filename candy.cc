// Copyright 2014 kevinew@leetcode Inc. All Rights Reserved.


#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define VI vector<int>
#define VS vector<string>

class Solution {
  public:
    int candy(vector<int> &ratings) {
      VI candys(ratings.size(), 1);
      // Visit from left to right.
      for (int i = 0; i < ratings.size() - 1; ++i) {
        if (ratings[i] < ratings[i + 1])
          candys[i + 1] = max(candys[i + 1], candys[i] + 1);
      }
      // Visit from right to left.
      for (int i = ratings.size() - 1; i > 0; --i) {
        if (ratings[i] < ratings[i - 1])
          candys[i - 1] = max(candys[i - 1], candys[i] + 1);
      }
      int sum = 0;
      for (int i = 0; i < candys.size(); ++i) sum += candys[i];
      return sum;
    }
};

int main(int argc, char **argv) {

  Solution s;
  vector<int> ratings(5, 3);

  ratings[0] = 6;
  ratings[1] = 2;
  ratings[2] = 8;
  ratings[3] = 9;
  ratings[4] = 7;
 
  cout << s.candy(ratings) << endl;

  return 0;
}
