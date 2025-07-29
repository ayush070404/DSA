class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int l = 0 , r = 0;
        int cnt = 0;
        int a = n+m;
        int ind1 = (n+m)/2;
        int ind2 = ind1-1;
        int ind1El = -1, ind2El = -1;

        while(l<n &&r<m){
            if(nums1[l]<nums2[r]){
                if(cnt == ind1) ind1El= nums1[l];
                if(cnt == ind2) ind2El = nums1[l];
                l++;
                cnt++;
            }
            else{
                if(cnt == ind1) ind1El= nums2[r];
                if(cnt == ind2) ind2El = nums2[r];
                r++;
                cnt++;
            }
        }
        while(l<n){
            if(cnt == ind1) ind1El= nums1[l];
            if(cnt == ind2) ind2El = nums1[l];
            l++;
            cnt++;
        }
        while(r<m){
            if(cnt == ind1) ind1El= nums2[r];
            if(cnt == ind2) ind2El = nums2[r];
            r++;
            cnt++;
        }

        if(a%2 == 1) return ind1El;

    return double(ind1El+ind2El)/2;
    }
};