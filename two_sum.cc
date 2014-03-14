// Copyright 2014 kevinew@leetcode Inc. All Rights Reserved.


#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


struct Data {
  int number, id;
};

bool Cmp(const Data& a, const Data& b) {
  return a.number < b.number;
}

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
      vector<int> result;
      vector<Data> datas;
      for (int i = 0; i < numbers.size(); ++i) {
        Data d;
        d.number = numbers[i];
        d.id = i + 1;
        datas.push_back(d);
      }
      sort(datas.begin(), datas.end(), Cmp);
      int i, j;
      i = 0;
      j = datas.size() -1;
      while (i < j) {
        if (datas[i].number + datas[j].number == target) {
          if (datas[i].id < datas[j].id) {
            result.push_back(datas[i].id);
            result.push_back(datas[j].id);
          } else {
            result.push_back(datas[j].id);
            result.push_back(datas[i].id);
          }
          return result;
        } else if (datas[i].number + datas[j].number < target) {
          ++i;
        } else {
          --j;
        }
      }
    }
};


int main(int argc, char **argv) {

  Solution s;
  vector<int> n;
  n.push_back(2);
  n.push_back(7);
  n.push_back(8);
  n.push_back(9);
  n = s.twoSum(n, 9);
  for (int i = 0; i < n.size(); ++i) {
    cout << n[i] << endl;
  }

  return 0;
}
