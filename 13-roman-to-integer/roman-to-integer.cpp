class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char ,int> roman ={
            {'I', 1}, {'V', 5}, {'X', 10},{'L', 50},{'C', 100}, {'D', 500}, {'M' ,1000}
        };
        int result = 0;
        for(int i =0 ; i<n ; i++){
            int curr = roman[s[i]];
            int next;
            if(i+1 < n) next = roman[s[i+1]];
            else next = 0;

            if(curr< next){
                result -= curr;
            }
            else{
                result+= curr;
            }
        }
    return result;
    }
};