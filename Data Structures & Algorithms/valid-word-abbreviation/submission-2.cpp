class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        string prefix="";
        string num="";

        int in=0;
        int check=0;

        while(in<abbr.size()){
            if(check>=word.size()) { 
                return false; 
            }
            if(abbr[in]>='a' && abbr[in]<='z' && abbr[in]!=word[check]) { 
                return false; 
            }
            else if(abbr[in]=='0') return false;
            else if(abbr[in]>'0' && abbr[in]<='9'){
                while(in<abbr.size() && abbr[in]>='0' && abbr[in]<='9'){
                    num+=abbr[in++];
                }

                int tem=stoi(num);
                num="";

                if(tem==0) return false;

                while(tem--){ check++; }
                if(check>word.size()) {
                    return false;
                }
            }
            else{
                in++; check++;
            }
        }
        return true;

    }
};