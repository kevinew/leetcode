class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      if (prices.size() == 0) return 0;
      int profit = 0;
      int start_data = prices[0];
      for (int i = 1; i < prices.size(); ++i) {
        if (prices[i - 1] > prices[i]) {  // 股价下跌
          profit += prices[i - 1] - start_data;
          start_data = prices[i];
        }
      }
      profit += prices[prices.size() - 1] - start_data;

      return profit;
    }
};
