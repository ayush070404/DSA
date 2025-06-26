class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> s;
        vector<int>unionarr;
        set<int>result;

        for(int n : nums1)
        {
            s.insert(n);
        }

        for (int num : nums2) {
            if (s.count(num))
            {
                result.insert(num); 
            }
        }

         return vector<int>(result.begin(), result.end());

    }
};