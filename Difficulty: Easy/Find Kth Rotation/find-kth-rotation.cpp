// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int count = 0;
        
        for(int i= 0 ; i<n ; i++){
            
            // if(i == 0){
            //     if(arr[i]<arr[i+1]) count++;
            // }
            // else{
                if(arr[i-1]>arr[i] && arr[(i+1)%n]>arr[i]) count= i;
            // }
            
        }
        return count;
        
    }
};
