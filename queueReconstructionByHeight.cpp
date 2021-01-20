class Solution {
public: 
    bool sort_criterion(vector<int>input1, vector<int>input2){
        if(input1[0] != input2[0]) return input1[0] > input2[0];
        else return input1[1] < input2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Lambda method for custom sorting
        sort(people.begin(), people.end(), [this](vector<int> a, vector<int> b) { return sort_criterion(a, b); });
        vector<vector<int>> ans;
        int height, rank;
        for(int i=0; i<people.size(); i++){
            if(i==0){
                ans.push_back(people[i]);
                continue;
            }
            height = people[i][0];
            rank = people[i][1];
            /*
                In case of $people after sorting: [ [7,0], [7,2], [6,1], ...... ]
                1. Now ans is [ [7,0] ], and [7, 2] wants to go in
                2. Now ans is [ [7,0], [7,2] ], and [6,1] wants to go in
                So we have to compare both rank and current height to determine inserting or not.
            */
            if(rank != i && height < ans[i-1][0]){
                ans.insert(ans.begin()+rank, people[i]);
            }
            else
            {
                ans.push_back(people[i]);
            }
        }
        return ans;
    }
};
