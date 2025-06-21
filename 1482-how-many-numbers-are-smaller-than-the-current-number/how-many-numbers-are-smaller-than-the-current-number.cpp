class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int , int> mp;

        for(int i = 0 ; i < n ; i++){
            if(mp.count(temp[i]) == 0){
                mp[temp[i]] = i;
            }
        }

        vector<int> ans;

        for(int num: nums){
            ans.push_back(mp[num]);
        }
    return ans;
    }
};