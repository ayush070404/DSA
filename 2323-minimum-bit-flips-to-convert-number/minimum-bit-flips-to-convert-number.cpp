class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start^goal;
        int cnt = 0;
        while(num != 0){
            num = (num & num -1); // counting setbits
            cnt++;
        }
        return cnt;
    }
};