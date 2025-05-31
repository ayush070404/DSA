class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // Your code here
        // if( (n &( 1 << k)) != 0) return true;  // calculating precedence
        // else return false;
        
        if(((n >> k)& 1 ) != 0) return true;
        else return false;
    }
};