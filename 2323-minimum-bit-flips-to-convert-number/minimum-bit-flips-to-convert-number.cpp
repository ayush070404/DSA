class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start^goal; // helps to identify where the flips are done(XOR)
        int cnt = 0;
        if(num == 0) return 0;
        while(num != 0){
            num = (num & num -1); // counting setbits
            cnt++;
        }
        return cnt;
    }
};