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
