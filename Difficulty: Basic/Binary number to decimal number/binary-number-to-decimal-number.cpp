class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int num = 0;
        int n = b.size();
        for(int i = n-1 ; i>=0 ; i--){
            num += (b[i] - '0')* pow(2, (n-1 - i));
        }
    return num;
    }
};

