class Solution {
  public:
    int divide(int dividend, int divisor) {
      int flag1 = 1, flag2 = 1;

      if (dividend < 0) {
        flag1 = -1;
        dividend = 0 - dividend;
      }
      if (divisor < 0) {
        flag2 = -1;
        divisor = 0 - divisor;
      }
      if (dividend < divisor) return 0;
      int ret = 1 + divide(dividend - divisor, divisor);

      if (flag1 + flag2 == 0) return 0 - ret;
      else return ret;                                                                                                                                                                                                                       
    }
};
