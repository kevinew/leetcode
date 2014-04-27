// Copyright 2014 kevinew.1221@gmail.com Inc. All Rights Reserved.
// Problem:
// Given an array of integers, every element appears three times except for one.
// Find that single one.

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int singleNumber(int A[], int n) {
      Init();
      for (int i = 0; i < n; ++i) {
        AddToBitBucket(A[i]);
      }

      CompressBitBucket();

      // for (int i = 0; i < 10; ++i) cout << bit_bucket_[i] << endl;

      return GetResult();
    }

  private:
    int bit_bucket_[100];
    int minus_flag_;

    void Init() {
      for (int i = 0; i < 100; ++i) bit_bucket_[i] = 0;
      minus_flag_ = 0;
    }

    void AddToBitBucket(int number) {
      int i = 0;
      long long u_number;
      
      u_number = number;
      if (number < 0) {
        u_number = -u_number;
        ++minus_flag_;
      }
      while (u_number) {
        bit_bucket_[i++] += u_number % 2;
        u_number /= 2;
      }
    }

    void CompressBitBucket() {
      for (int i = 0; i < 100; ++i) bit_bucket_[i] = bit_bucket_[i] % 3;
      minus_flag_ %= 3;
    }

    int GetResult() {
      long long result = 0;
      for (int i = 100 - 1; i >= 0; --i) {
        result = result*2 + bit_bucket_[i];
      }
      // cout << result << endl;
      if (minus_flag_ > 0) result *= -1;
      return result;
    }
};


int main(int argc, char **argv) {

  Solution s;
  int a[] = {2, 2, 3, 2};

  cout << "\nresult = " << s.singleNumber(a, 4) << endl;

  return 0;
}
