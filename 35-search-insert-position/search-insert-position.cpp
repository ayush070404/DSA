class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int n = nums.size();
        int low =0, high= n-1;
        int ans = n;  // this woll holf when    -->2 doesn't hold
        while(low<= high){
            int mid = low + (high-low)/2 ;
            
            if(nums[mid] == x) return mid;
            
            else if(nums[mid] > x){   //--> 2
                ans = mid;
                
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
        
    }
};