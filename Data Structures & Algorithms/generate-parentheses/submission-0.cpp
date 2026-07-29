class Solution {
public:
    vector<string> ans;
    bool valid(string temp){
        int maxi=0;
        for(char c:temp){
            if(c=='(') maxi++;
            else maxi--;
            if(maxi<0) return false;
        }
        return maxi==0;
    }
    void generate(int cnt,int n,string temp){
        if(cnt==n and  valid(temp)){
            ans.push_back(temp);
            return;
        }
        if(cnt>n) return;
        generate(cnt+1,n,temp+'(');
        generate(cnt+1,n,temp+')');

    }
    vector<string> generateParenthesis(int n) {
        generate(0,n*2,"");
        return ans;
    }
};
