// 1. n > 0   
// 2. n == 0 
// 3. n < 0

class Solution {
public:
    double pow(double x, int n) {
        if (0 == n) return 1;
        int flag = 1;
        if (n < 0) {
            flag = -1;
            n *= -1;
        }
        double half_pow = pow(x, n/2);
        double res = half_pow * half_pow;
        if(n%2) res *= x;
        
        if (flag == -1) return 1 / res;
        else return res;
    }
};
