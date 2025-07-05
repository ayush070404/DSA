class Solution {
public:
    int getMinCount(vector<int>& freq) {
        int mincount = INT_MAX;
        for (int count : freq) {
            if (count != 0)
                mincount = min(mincount, count);
        }
        return mincount;
    }
    int getMaxCount(vector<int>& freq) {
        int maxcount = 0;
        for (int count : freq) {
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
    int beautySum(string s) {
       int sum = 0;
       for(int i = 0;i<s.size();i++){
        vector<int> freq(26,0);
        for(int j = i;j<s.size();j++){
          freq[s[j] - 'a']++;
          int beauty = getMaxCount(freq) - getMinCount(freq);
          sum+= beauty;
        }
       }
       return sum;
    }
};