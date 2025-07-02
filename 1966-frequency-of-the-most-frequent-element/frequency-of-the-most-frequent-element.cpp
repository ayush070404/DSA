class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long left = 0, right = 0;
        long long windowSum = 0;
        long maxElement = 0;
        while(right < nums.size()){

            windowSum += nums[right];

            while( nums[right]*(right -left +1) - windowSum > k){
                windowSum -= nums[left];
                left++;
            }

            maxElement = max(maxElement , right -left +1);
            right++;
        }

    return maxElement;   
    }
};