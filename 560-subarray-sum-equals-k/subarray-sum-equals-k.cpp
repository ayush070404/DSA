class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n=arr.size();
map<int,int>mpp;
int count=0;
int sum=0;
//start of the for loop
for(int i=0;i<n;i++)
{
  sum=sum+arr[i];
  	 if(sum==k)
{
count++;
}
if(mpp[sum-k]>0)
{
count+=mpp[sum-k];
}
mpp[sum]++;
}
//end of the for loop
return count;

    }
};