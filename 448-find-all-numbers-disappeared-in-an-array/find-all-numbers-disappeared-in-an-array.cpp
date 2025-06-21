class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> hash(n+1 , 0);

        for(int i = 0 ; i< n ; i++){
            hash[nums[i]]++;
        }

        for(int j = 1 ; j < n +1 ; j++){
            if(hash[j] == 0){
                ans.push_back(j);
            }
        }
    return ans;
    }
};