// User function Template for C++

class Solution {
  public:
  
    void heapify_down(vector<int> &arr ,int ind){
        int n = arr.size();
        int largest = ind , lchild = 2*ind+1 , rchild= 2*ind+2;
        
        if(lchild< n && arr[lchild]> arr[largest]){
            largest = lchild; 
        }
        if(rchild< n && arr[rchild]> arr[largest]){
            largest = rchild; 
        }
        
        if(largest != ind){
            swap(arr[largest], arr[ind]);
            heapify_down(arr, largest);
        }
        
    }
  
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        
        for(int i = N-1 ; i>=0 ; i--){
            heapify_down(arr , i);
        }
    }
};
