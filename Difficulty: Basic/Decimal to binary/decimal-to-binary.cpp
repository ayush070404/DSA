class Solution {
  public:
    string decToBinary(int n) {
        // code here
        string res ="";
        while( n != 1){
            if(n % 2 == 1) res += '1';
            else res+= '0';
            n = n/2;
        }
        if( n ==1) res+= '1';
        reverse(res.begin(), res.end());
        
    return res;
    }
};