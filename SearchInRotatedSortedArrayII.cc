class Solution {
public:
    bool search(int A[], int n, int target) {
        if (0 == n) return -1;
        int h, l, mid;
        int base = A[0];
        
        if (base == target) return true;
        l = 1;
        h = n - 1;
        
        // add the following 2 lines is OK.
        while (A[l] == base) ++l;
        while (A[h] == base) --h;
        
        while (l <= h) {
            mid = (h -l) / 2 + l;
        
            if (target == A[mid]) return true;
            if (target < base) {  // 先判断目标值与基准值的大小关系
                // 判断中间值与基准值的大小关系
                if (A[mid] > base) {l = mid + 1;}  
                else {  // 目标值与中间值在同一类区间段时，就是普通的二分查找了
                    if (target < A[mid]) h = mid - 1;
                    else l = mid + 1;
                }
                
            } else {
                if (A[mid] < base) {h = mid - 1;}
                else {
                    if (target < A[mid]) h = mid - 1;
                    else l = mid + 1;
                }
            }
        }
        return false;
    }
};
