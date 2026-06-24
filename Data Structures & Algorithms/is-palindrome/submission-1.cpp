class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            while(!(isalpha(s[i]) ||isdigit(s[i]))) i++;
            while(!(isalpha(s[j]) ||isdigit(s[i]))) j--;
            if(i>=j)break;
            if(tolower(s[i])!=tolower(s[j]))  return false;
            i++;
            j--;

        }
        return true;
    }
};
