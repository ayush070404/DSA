class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n =arr.size();
        int largest = arr[0];
        int seclar = -1;
        
        for(int i =0 ; i< n ; i++){
            if(largest< arr[i]){
                seclar = largest;
                largest = arr[i];
                
            }
            else if(seclar < arr[i] && arr[i]<largest){
                seclar = arr[i];
            }
        }
    return seclar;
        
    }
};