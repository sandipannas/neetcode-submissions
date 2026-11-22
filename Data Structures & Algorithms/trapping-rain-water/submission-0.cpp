class Solution {
public:
    int trap(vector<int>& h) {
        vector<pair<int,int>> limit;
        
        int pre=h[0];
        for(int i=0;i<h.size();i++){
            if(pre<h[i]) pre=h[i];
            limit.push_back({pre,0});
        }

        pre=h.back();
        for(int i=h.size()-1;i>=0;i--){
            if(pre<h[i]) pre=h[i];
            limit[i].second=pre;
        }

        int sum=0;
        for(int i=0;i<h.size();i++){
            sum+=min(limit[i].first,limit[i].second)-h[i];
        }

        return sum;
    }
};