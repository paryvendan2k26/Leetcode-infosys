class Solution {
public:
    int lengthOfLastWord(string s) {
        string str="";
        int n=s.size();
        bool x=false;
        int start=n-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                start=i;
                break;
            }
            
        }
        int end =-1;
        for(int i=start;i>=0;i--){
            if(s[i]==' '){
                end=i;
                break;
            }
            
        }

        return start-end;

    }
};