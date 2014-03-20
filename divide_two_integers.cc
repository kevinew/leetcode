// O(lgN)
// Analyse: store divisor divisor+divisor divisor+divisor+divisor  ... 65536
// compare dividend and 65536 65536+65536 65536+65536+65536

// Conclude a Method:  
// Prestore long a[n]
// divisor * 2^0
// divisor * 2^1
// divisor * 2^2
// divisor * 2^4
// ...  just more than the biggest int(2147483647).

// Copyright 2014 kevinew@leetcode Inc. All Rights Reserved.

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Solution {                                                                 
  public:                                                                        
    int divide(long long dividend, long long divisor) {                                      
      int ret, i;                                                                   
      int flag1 = 1, flag2 = 1;                                                  

      if (dividend < 0) {
        flag1 = -1;
        dividend = 0 - dividend;
      }
      if (divisor < 0) {
        flag2 = -1;
        divisor = 0 - divisor;
      }

      vector<long long> a;                                                               
      a.reserve(33);                                                                
      a[0] = divisor;                                                               
      for (i = 1; ; ++i) {                                                      
        a[i] = a[i - 1] + a[i - 1];                                                 
        if (a[i] > dividend) break;                                                 
      }                                                                             
      --i;                                                                          

      int result = 0;                                                               
      bool first = false;                                                           
      while (i >= 0) {                                                              
        result = result << 1;                                                       
        if (dividend >= a[i]) {                                                     
          result += 1;                                                              
          dividend -= a[i];                                                         
        }         
        --i;
      }

      if (flag1 + flag2 == 0) return -result;
      else return result;                                                                
    }
};  

int main(int argc, char **argv) {

  Solution s;

  // When I change the args of divide from int to long long,
  // then passed this case.
  cout << s.divide(-1010369383, -2147483648) << endl;

  return 0;
}
