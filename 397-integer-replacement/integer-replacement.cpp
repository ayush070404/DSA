class Solution {
public:
    int integerReplacement(int n) {
        long long num = n; // Use long to avoid overflow for INT_MAX
        int cnt = 0;
        while(num > 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                if (num == 3 || num % 4 == 1) {
                    num -= 1;
                } else {
                    num += 1;
                }
            }
            cnt++;
        }
        return cnt;
    }
};
