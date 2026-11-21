class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        string answer=""; answer.reserve(n+m);
        int ins=0;

        while(ins<n && ins<m ){
            answer.push_back(word1[ins]);
            answer.push_back(word2[ins]);
            ins++;
        }

        if(ins<n){
            answer.append(word1,ins,n-ins);
        }
        if(ins<m){
            answer.append(word2,ins,m-ins);
        }

        return answer;
    }
};