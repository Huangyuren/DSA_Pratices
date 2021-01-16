/*
 * Thinking: firstly list out all idle positions.
 * Hence, we can view how many tasks that can be inserted
 * in to replace these idle time. If resulting idle_capacity < 0,
 * we know that this is invalid case, return tasks.size(). If resulting
 * idle_capacity > 0, we know that there still has idle position,
 * return idle_capacity + tasks.size() instead.
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        unordered_map<char, int> mymap;
        int curr_max=0;
        char curr_max_key;
        for(int i=0; i<tasks.size(); i++){
            mymap[tasks[i]]++;
            if(mymap[tasks[i]] > curr_max){
                curr_max = mymap[tasks[i]];
                curr_max_key = tasks[i];
            }
        }
        int idle_capacity = (curr_max-1) * n;
        int tmp;
        for(auto& cur : mymap){
            if(cur.first != curr_max_key){
                tmp = min(curr_max-1, cur.second);
                idle_capacity -= tmp;
            }
        }
        if(idle_capacity < 0)
            return tasks.size();
        else
            return idle_capacity + tasks.size();
    }
};
