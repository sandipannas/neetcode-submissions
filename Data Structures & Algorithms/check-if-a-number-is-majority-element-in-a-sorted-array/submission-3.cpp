class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int start=-1;
        int left=0,right=nums.size()-1;
        while(left<=right){
            //cout<<start<<endl;
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                right=mid-1;
            }
            else{
                start=mid;
                left=mid+1;
            }
        }
        int end=nums.size();
        //cout<<"fjiahsdfkljhsf"<<endl;
        left=0;
        right=nums.size()-1;

        while(left<=right){
            //cout<<end<<endl;
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                left=mid+1;
            }
            else{
                end=mid;
                right=mid-1;
            }
        }

        int a=end-1-start;
        //cout<<end<<" "<<start;
        int b=nums.size()/2;
        return a>b?true:false;


    }
};
