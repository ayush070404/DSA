class Solution {
  public:
    int countSetBits(int n) {
        if (n == 0) return 0;

        // Find the highest power of 2 <= n
        int x = 0;
        while ((1 << (x + 1)) <= n)
            x++;

        // Total set bits from 1 to 2^x - 1
        int bitsUpTo2PowX = x * (1 << (x - 1));

        // MSB set bits from 2^x to n
        int msbBits = n - (1 << x) + 1;

        // Remaining part
        int rest = countSetBits(n - (1 << x));

        return bitsUpTo2PowX + msbBits + rest;
    }
};


