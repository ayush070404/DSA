class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> nge;
        stack<int> st;

        for(int i = 2*n -1 ; i>= 0 ; i--){

            while(!st.empty() && st.top()<= nums[i% n]){
                st.pop();
            }
            if(i < n ){
                if(st.empty()) nge[i] = -1;
                else nge[i] = st.top();
            }

            st.push(nums[i% n]);
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            ans.push_back(nge[i]);
        }
    return ans;
    }
};