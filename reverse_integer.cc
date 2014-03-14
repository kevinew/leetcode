// Copyright 2014 kevinew@leetcode Inc. All Rights Reserved.

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int reverse(int x) {
      int flag, result;
      
      flag = x > 0 ? 1 : -1;
      x *= flag;
      result = 0;
      while (x) {
        result = result * 10 + x % 10;
        x /= 10;
      }
      result *= flag;
      return result;
    }
};


int main(int argc, char **argv) {

  Solution s;
  cout << s.reverse(4) << endl;
  cout << s.reverse(47395599) << endl;
  cout << s.reverse(-7395599) << endl;

  return 0;
}
