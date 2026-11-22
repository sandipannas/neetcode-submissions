class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;

        int left=0;
        while(left<min(k,(int)nums.size())){
            if(map.count(nums[left])) return true;
            map[nums[left++]]++;
        }

        left=0;
        
        for(int i=k;i<nums.size();i++){
            if(map.count(nums[i]) && map[nums[i]]!=0) return true;
            map[nums[i]]++;
            map[nums[left++]]--;
        }
        return false;
    }
};