// Score is the snake itself length
class SnakeGame {
private:
    deque<pair<int, int>> body; // Using deque, back is head, front is tail
    set<pair<int, int>> bodyhistory;
    vector<vector<int>> foodinternal;
    int row, col, foodcounter, score;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        row = height; col = width;
        foodcounter = 0; score = 0;
        foodinternal = food;
        body.push_back({0,0});
        bodyhistory.insert({0,0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int currow = body.back().first, currcol = body.back().second;
        auto backup = body.front();
        bodyhistory.erase(body.front());
        body.pop_front();
        if(direction == "R"){
            currcol++;
        }
        if(direction == "D"){
            currow++;
        }
        if(direction == "U"){
            currow--;
        }
        if(direction == "L"){
            currcol--;
        }
        if(currow<0 || currow>=row || currcol<0 || currcol>=col || bodyhistory.count({currow, currcol})) return -1;
        body.push_back({currow, currcol});
        bodyhistory.insert({currow, currcol});
        // Should check for foodcounter's validity to avoid seg fault
        if(foodcounter >= foodinternal.size()){
            return score;
        }
        if(currow == foodinternal[foodcounter][0] && currcol == foodinternal[foodcounter][1]){ // Eat food, should restore popped tail
            bodyhistory.insert(backup);
            body.push_front(backup);
            foodcounter++; // increment only if the snake eats
            score++;
        }
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
