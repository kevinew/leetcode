class Solution {
public:
    int search(int A[], int n, int target) {
        if (0 == n) return -1;
        int h, l, mid;
        int base = A[0];
        
        if (base == target) return 0;
        l = 1;
        h = n - 1;
        while (l <= h) {
            mid = (h -l) / 2 + l;
        
            if (target == A[mid]) return mid;
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
        return -1;
    }
};
