class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    //a function to find the ultimate parent of a node
    int find_parent(int node){
        if(parent[node]==node){
            return node;
        }

        //path compression means as we work backwards to find the ultimate parent
        //we will update the parents of the middle node as the ultimate parent
        return parent[node]=find_parent(parent[node]);
    }

    void union_node(int u,int v){
        //as i have already used find() on both u and v parent[u],parent[v] must be their 
        //ultimate parents
        if(rank[parent[u]]>rank[parent[v]]){
            parent[parent[v]]=parent[u];
        }
        else if(rank[parent[u]]<rank[parent[v]]){
            parent[parent[u]]=parent[v];
        }
        else{
            parent[parent[u]]=parent[v];
            rank[parent[v]]++;
        }
    } 

    int countComponents(int n, vector<vector<int>>& edges) {

        parent.resize(n); for(int i=0;i<n;i++){ parent[i]=i; }
        rank.resize(n,1); 
        int count=n;   
        
        for(auto& edge:edges){
            int ultimate_parent_of_u=find_parent(edge[0]);
            int ultimate_parent_of_v=find_parent(edge[1]);


            if(ultimate_parent_of_u!=ultimate_parent_of_v){
                
                //because there will be a merge of two different groups into one group
                count--;
                union_node(edge[0],edge[1]);
            }
        }

        return count;   
    }
};