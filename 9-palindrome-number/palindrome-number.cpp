class Solution {
public:
    bool isPalindrome(int x) {
        if (x == INT_MIN) {
        return 0; // Directly return 0 since negation will cause overflow.
    }
        if( x< 0) return false;
        int num = x;
        int reversed = 0;
        while(num>0){
            int lastdigit = num% 10;
            if (reversed > (INT_MAX - lastdigit) / 10) {
            return 0; // Return 0 to indicate overflow.
        } 
            reversed = reversed*10 + lastdigit;
            num = num/10;
        }
        if (x == reversed) {
            return true;
        }
        else{
            return false;
        }
            
        }
};