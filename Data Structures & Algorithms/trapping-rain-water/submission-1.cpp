class Solution {
public:
    int trap(vector<int>& h) {
        int left=0, left_max=h[left];
        int right=h.size()-1, right_max=h[right];

        int sum=0;

        while(left<right){
            if(left_max<h[left]) left_max=h[left];
            if(right_max<h[right]) right_max=h[right];

            if(left_max<right_max) sum+=left_max-h[left++];
            else sum+=right_max-h[right--];
        }
        return sum;
    }
};