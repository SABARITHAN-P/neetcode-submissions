class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxA=INT_MIN,maxB=INT_MIN,maxC=INT_MIN;
        int n=triplets.size();
        vector<vector<int>> temp;
        for(int i=0;i<n;i++){
            if((target[0]>=triplets[i][0] and 
            target[1]>=triplets[i][1] and 
            target[2]>=triplets[i][2])
            ) 
                temp.push_back(triplets[i]);
        }
        int m=temp.size();
        for(int i=0;i<m;i++){
            maxA=max(maxA,temp[i][0]);
            maxB=max(maxB,temp[i][1]);
            maxC=max(maxC,temp[i][2]);
        }

        return target[0]==maxA and target[1]==maxB and target[2]==maxC;
    }
};
