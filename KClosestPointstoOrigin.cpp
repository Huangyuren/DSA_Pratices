class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        partial_sort(points.begin(), points.begin()+k, points.end(), \
            [](vector<int>&a, vector<int>& b) {
                return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
            });
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }

//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
//         priority_queue<vector<int>, vector<vector<int>>, compare> mypq; // max heap, pop out Kth element
//         for(auto& x : points){
//             mypq.push(x);
//             if(mypq.size() > k){
//                 mypq.pop();
//                 break;
//             }
//         }
//         while(mypq.size()){
//             auto curr = mypq.top(); mypq.pop();
//             res.push_back(curr);
//         }
//         return res;
//     }
// private:
//     struct compare {
//         bool operator()(vector<int>& a, vector<int>& b){
//             return (pow(a[0], 2)+pow(a[1], 2)) < (pow(b[0],2)+pow(b[1],2));
//         }
//     };
};
