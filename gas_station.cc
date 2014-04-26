// Copyright 2014 kevinew@leetcode Inc. All Rights Reserved.
// Solve:
//   a[] = {1 2 -3 5 6 -6}
//   so we can consider b[] = [a[] a[]], just is joint with 2 a.
//   Find the n(a)-length, sum is not less than 0.

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define VI vector<int>
#define VS vector<string>


// Max sum of sub array - Just use 2 same array to concat.
// 1 -1 5 6   =>  1 -1 5 6 1 -1 5 6

class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
      int n = gas.size();
      vector<int> a;

      for (int i = 0; i < n; ++i) gas[i] -= cost[i];
      // concat with 2 same array.
      a.insert(a.end(), gas.begin(), gas.end());
      a.insert(a.end(), gas.begin(), gas.end());

      int start, count, sum;
      start = 0;
      count = 0;
      sum = 0;
      for (int i = 0; i < a.size(); ++i) {
        sum += a[i];
        count++;

        if (sum < 0) {
          count = 0;
          sum = 0;
          start = i + 1;
          continue;
        }
        if (count == n) return start;
      }
      return -1;
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
