class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        vector<int> arr;
        int l = 0 ,r = 0;
        while(l < n && r < m){
            if(nums1[l]<=nums2[r]){
                arr.push_back(nums1[l]);
                l++;
            }
            else{
                arr.push_back(nums2[r]);
                r++;
            }
        }
        while(l<n){
            arr.push_back(nums1[l]);
            l++;
        }
        while(r<m){
            arr.push_back(nums2[r]);
            r++;
        }

        if((n+m)%2 == 0) return double(arr[(n+m)/2] + arr[((n+m)/2 )-1])/2;
        else return (arr[(n+m)/2]);
    }
};