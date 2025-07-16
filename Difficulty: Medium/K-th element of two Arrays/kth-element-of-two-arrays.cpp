class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();

        vector<int> arr;
        for(int i= 0 ; i<n ; i++){
          arr.push_back(a[i]);
        }
        for(int i= 0 ; i<m ; i++){
          arr.push_back(b[i]);
        }
        sort(arr.begin(), arr.end());

        int ans = arr[k-1];

    return ans;
  }
};