class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n ,-1);

        for(int i = 0 ; i< n ; i++){
            int num = nums1[i];
            for(int j = 0 ; j< m; j++){
                if(nums2[j] == num ) {
                    for(int ind = j+1 ; ind< m ; ind++){
                        if(nums2[ind]> num){
                            ans[i] =nums2[ind];
                            break;
                        }
                    }
                }
            }

        }
    return ans;
    }
};