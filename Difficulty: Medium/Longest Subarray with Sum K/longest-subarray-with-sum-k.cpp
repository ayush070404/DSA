class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        unordered_map<int , int>prefixSum;
        int sum = 0, len = 0;
        
        for(int i=0 ; i< n ;i++){
            sum+= arr[i];
            
            if(sum == k ){
                len = i+1;
            }
            
            if(prefixSum.find(sum-k)!=prefixSum.end()){
                len = max(len , i-prefixSum[sum-k]);
            }
            
            if(prefixSum.find(sum) == prefixSum.end()){
                prefixSum[sum] = i;
            }
        }
        return len;
    }
};