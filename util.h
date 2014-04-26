// Copyright 2014 kevinew.1221@gmail.com Inc. All Rights Reserved.


#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define VI vector<int>
#define VII vector<vector<int> >
#define VS vector<string>
#define VSS vector<vector<string> >

#define SI set<int>
#define SS set<string>

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
