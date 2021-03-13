class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() == 0) return 0;
        int n = position.size();
        // Should be max heap, since we will count from back(closest to target), why can not count from front?
        // Because two cars collide, aftermath speed is min(speed_1, speed_2), we only need to look at
        // how much time it costs to get to the target
        priority_queue<pair<int, float>, vector<pair<int, float>>, less<pair<int, float>>> mypq;
        for(int i=0; i<n; i++){
            int dist = target - position[i];
            mypq.push({position[i], dist / float(speed[i])});
        }
        int res = 0;
        float currlongestime = 0;
        while(mypq.size()){
            auto tmp = mypq.top(); mypq.pop();
            if(tmp.second > currlongestime){ // if the latter needs  time to go to target, another car fleet
                res++;
                currlongestime = tmp.second;
            }
        }
        return res;
    }
};
