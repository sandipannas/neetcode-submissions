class Solution:

    def encode(self, strs: List[str]) -> str:
        new_str=""
        for item in strs:
            size=len(item)
            new_str+="*"+str(size)+"*"+item
        print(new_str)
        return new_str;

    def decode(self, s: str) -> List[str]:
        i=0
        answer=[]
        while i<len(s):
            if s[i]=='*' :
                i=i+1
                num=''
                while s[i]!='*':
                    num+=s[i]
                    i+=1
                i+=1
                num=int(num)

                st=""
                while num!=0:
                    st+=s[i]
                    num-=1
                    i+=1
                answer.append(st)
        return answer