// We can decomposite this into 2 one-pass checkings
// Then we can develop single one-pass solution based on this
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // // Firstly check solution exists or not
        // int accu=0, n=gas.size();
        // for(int i=0; i<n; i++){
        //     accu += gas[i]-cost[i];
        // }
        // if(accu < 0) return -1;
        // // Secondly find out the starting point (we are sure that there exists solution)
        // int res = 0, currgas = 0;
        // for(int i=0; i<n; i++){
        //     currgas += gas[i] - cost[i];
        //     if(currgas < 0){
        //         // current starting position is not starting point, so proceed on next res
        //         res = i+1;
        //         currgas = 0;
        //     }
        // }
        // return res;
        
        // One pass solution
        int res = 0, n = gas.size(), gasaccu = 0, gascurr = 0;
        for(int i=0; i<n; i++){
            gascurr += gas[i] - cost[i];
            if(gascurr < 0){
                gasaccu += gascurr;
                gascurr = 0;
                res = i+1;
            }
        }
        gasaccu += gascurr;
        return gasaccu < 0 ? -1 : res;
    }
};
