// User function Template for C++

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // write your code here
        vector<int> ans;
        int num = 0;
        for(int i = 0 ; i < queries; i++){
            int ind = indices[i];
            num = arr[ind];
            int cnt = 0;
            
            for(int j = ind+1 ; j < n ; j++){
                if(num <arr[j]) cnt++;
            }
            
            ans.push_back(cnt);
            cnt = 0;
        }
    return ans;   
    }
};