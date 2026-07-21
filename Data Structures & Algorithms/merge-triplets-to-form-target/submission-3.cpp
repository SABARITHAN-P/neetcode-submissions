class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxA=INT_MIN,maxB=INT_MIN,maxC=INT_MIN;
        int n=triplets.size();
        for(int i=0;i<n;i++){
            if (triplets[i][0] <= target[0] &&
                triplets[i][1] <= target[1] &&
                triplets[i][2] <= target[2]) {

                    maxA = max(maxA, triplets[i][0]);
                    maxB = max(maxB, triplets[i][1]);
                    maxC = max(maxC, triplets[i][2]);
            }
        }
        return target[0]==maxA and target[1]==maxB and target[2]==maxC;
    }
};
