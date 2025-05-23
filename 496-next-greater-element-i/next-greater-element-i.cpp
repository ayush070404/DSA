class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;  // map from num -> next greater
        stack<int> st;

        // Traverse nums2 from right to left to compute NGE
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            nge[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }

        // Use the map to build the result for nums1
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nge[num]);
        }

        return ans;
    }
};
