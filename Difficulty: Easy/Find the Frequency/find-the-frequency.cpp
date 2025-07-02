/*Function to find frequency of x
 * x : element whose frequency is to be found
 * arr : input vector
 */
class Solution {
  public:
    int findFrequency(vector<int> arr, int x) {
        // Your code here
        int n = arr.size();
        unordered_map<int , int> mpp;
        
        for(int i=0; i<n ; i++){
            mpp[arr[i]]++;
        }
        
        return mpp[x];
        
    }
};