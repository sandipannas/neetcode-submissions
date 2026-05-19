class Solution {
public:
    void travel( vector<vector<int>>& adlist,vector<int>& visited,int node){
        if(visited[node]){ return; }
        visited[node]=1;

        for(int i:adlist[node]){
            travel(adlist,visited,i);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adlist(n);
       vector<int> visited(n);

       for(auto& both:edges){
        adlist[both[0]].push_back(both[1]);
        adlist[both[1]].push_back(both[0]);
       }

       int count=0;

       for(int i=0;i<n;i++){
        if(!visited[i]){ travel(adlist,visited,i); count++;}
       }
       
       return count;

    }
};
