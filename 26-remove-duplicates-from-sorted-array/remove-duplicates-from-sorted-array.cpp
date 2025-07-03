class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector <int> arr;
        arr.push_back(nums[0]);
        for(int i=1; i<n ; i++){
            if(nums[i] != arr.back()){
                arr.push_back(nums[i]);
            }
        }
        nums = arr;
    return arr.size();
    }
};