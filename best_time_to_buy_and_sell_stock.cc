// Copyright 2014 kevinew@leetcode Inc. All Rights Reserved.

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 每次股价下跌时进行一次计算
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      if (prices.size() <= 1) return 0;
      int profit = 0;
      int start_data = prices[0];
      int max_profit = 0;
      for (int i = 1; i < prices.size(); ++i) {
        start_data = min(start_data, prices[i]);
        max_profit = max(max_profit, prices[i] - start_data);
      }

      if (max_profit < prices[prices.size() - 1] - start_data) {
        max_profit = prices[prices.size() - 1] - start_data;
      }

      return max_profit;
    }
};

int main(int argc, char **argv) {
  Solution s;
  vector<int> prices;
  prices.push_back(1);
  prices.push_back(2);
  cout << s.maxProfit(prices) << endl;

  return 0;
}
