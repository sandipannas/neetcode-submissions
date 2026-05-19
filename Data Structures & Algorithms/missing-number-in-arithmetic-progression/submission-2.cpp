class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int a=arr[0],n=arr.size();
        int d=(arr.back()-arr.front())/n;
        if(d==0){return arr[0];}
        int left=0,right=n-1;
    
        int last=0;
        while(left<=right){
           int mid=left+(right-left)/2;
           int com=a+(mid)*d;

           if(arr[mid]==com){
            left=mid+1;
           }
           else{
            right=mid-1;
            last=com;
           }
        }
        return last;

    }
};
