class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if (n % groupSize != 0) return false;
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;
        for(int card:hand){
            mp[card]++;
        }
        int run=0;
        while(run<n/groupSize){
            run++;
            int cnt=0;
            int prev;
            for(int card:hand){
                if(cnt==groupSize) break;
                if(mp[card] == 0) continue;
                if(cnt==0){
                    cnt++;
                    prev=card;
                    mp[card]--;
                }
                else{
                    if(card==prev+1 and mp[card]>0) {
                        cnt++;
                        mp[card]--;
                        prev=card;
                    }
                    else if(card==prev) continue;
                    else return false;
                }
            }
            if(cnt!=groupSize) return false;;
        }
        return true;
    }
};
