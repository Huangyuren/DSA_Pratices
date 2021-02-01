class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<int> state0(n, 0);// rest
        vector<int> state1(n, 0);// buy
        vector<int> state2(n, 0);// sell
        state0[0] = 0;
        state1[0] = -1*prices[0];
        state2[0] = 0;// no stocks for 1st iteration to sell.
        for(int i=1; i<n; i++){
            state0[i] = max(state0[i-1], state2[i-1]);// no act or sell->rest
            state1[i] = max(state0[i-1] - prices[i], state1[i-1]);// rest->buy or no act
            state2[i] = state1[i-1] + prices[i];// buy->sell
            // Should be aware that prices are all indexed "i", since no matter buy or sell,
            // are both based on current prices.
        }
        return max(state0[n-1], state2[n-1]);// last action may not be buying
    }
};
