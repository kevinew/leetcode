// O(lgN)
// store divisor divisor+divisor divisor+divisor+divisor  ... 65536
// compare dividend and 65536 65536+65536 65536+65536+65536
 
class Solution {
  public:
    int divide(int dividend, int divisor) {
      int ret;
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

      if (divisor == 1) ret = dividend;
      else {
        ret = 1 + divide(dividend - divisor, divisor);                                                                                                                                                                                       
      }
      if (flag1 + flag2 == 0) return 0 - ret;
      else return ret;
    }
};
