// Some techniques need to clarify
// Utilizing single vector res to return
// See comments
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] > 0 || res.size()==0 || res.back() < 0){ // curr element > 0 or curr element < 0 and check for same direciton
                res.push_back(asteroids[i]); // push back to answer list, it is done
            }
            else if(res.back() <= abs(asteroids[i])){ // Since if current element is larger than asteroids[i], asteroids[i] will be distroyed
                // Check for equal or not
                if(res.back() < abs(asteroids[i])){
                    i--;
                }
                res.pop_back();
            }
        }
        return res;
    }
};
