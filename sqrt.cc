// Copyright 2014 kevinew@leetcode Inc. All Rights Reserved.

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int sqrt(int x) {
      int min, max, mid;

      if (0 == x) return x;
      min = 1;
      max = x;
      while(min <= max) {
        mid = (max - min) / 2 + min;
        if (mid == x / mid) {
          return mid;
        } else if (mid < x / mid) {
          min = mid + 1;
        } else {
          max = mid - 1;
        }
      }
      return max;
    }
};


int main(int argc, char **argv) {

  Solution s;
  cout << s.sqrt(4) << endl;
  cout << s.sqrt(2147395599) << endl;

  return 0;
}
