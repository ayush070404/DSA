class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> map;
        vector<int> ans;
        for(int num: nums){
            map[num]++;

            if(map[num]== n/3 +1){
                ans.push_back(num);
            }
        }
    return ans;
    }
};