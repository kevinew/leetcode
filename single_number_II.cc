// Problem:
// Given an array of integers, every element appears three times except for one.
// Find that single one.

class Solution {
  public:
    int singleNumber(int A[], int n) {
      for (int i = 0; i < n; ++i) {
        AddToBitBucket(A[i]);
      }

      CompressBitBucket();

      return GetResult();
    }

  private:
    int bit_bucket_[100];

    void AddToBitBucket(int number) {
      int i = 0;
      while (number) {
        bit_bucket_[i] += number % 2;
        number >>= 1;
      }
    }

    void CompressBitBucket() {
      for (int i = 0; i < 100; ++i) bit_bucket_[i] = bit_bucket_[i] % 3;
    }

    int GetResult() {
      int result = 0;
      for (int i = 100 - 1; i >= 0; --i) result = result<<1 + bit_bucket_[i];
      return result;
    }
};
