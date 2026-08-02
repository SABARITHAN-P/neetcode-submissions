class Solution {
public:
    int cnt=0;
    void expand(string s,int l,int r){
        while(l>=0 and r<s.length()){
            if(s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
            else break;
        }
    }
    int countSubstrings(string s) {
        for(int i=0;i<s.length();i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }
        return cnt;
    }
};
