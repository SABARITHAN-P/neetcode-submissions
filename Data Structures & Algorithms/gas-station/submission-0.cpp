class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot_gas=0,tot_cost=0,tank=0,n=gas.size(),start=0;;
        for(int i=0;i<n;i++){
            tot_gas+=gas[i];
            tot_cost+=cost[i];
            tank+=gas[i]-cost[i];
            if(tank<0){
                tank=0;
                start=i+1;
            }
        }
        if(tot_cost>tot_gas) return -1;
        return start;
    }
};
