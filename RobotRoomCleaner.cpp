/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
// Two things are critical, first, the robot has its current direction.
// Second, the robot has its current position.
// Current position is one unit offset/movement along current direction
// So in each move, we first verify current direction (int i%4), then move one unit away (tmprow, tmpcol)
// Remember to turnRight or Left because robot.move() depends on its internal directions!
class Solution {
public:
    void cleanRoom(Robot& robot) {
        clean(robot, 0, 0, 0); // (position information), direction counter
        return;
    }
    void clean(Robot& robot, int currow, int currcol, int currdirection){
        robot.clean(); // clean this room
        string currstr = to_string(currow)+" "+to_string(currcol);
        myset.insert(currstr);
        for(int i=currdirection; i < currdirection+4; i++){
            int tmprow = currow + direction[i%4][0];
            int tmpcol = currcol + direction[i%4][1];
            if(myset.count(to_string(tmprow)+" "+to_string(tmpcol)) == 0 && robot.move()){
                clean(robot, tmprow, tmpcol, i%4);
            }
            robot.turnRight();
        }
        // Restoring to previous position
        robot.turnRight(); robot.turnRight();
        robot.move();
        robot.turnRight(); robot.turnRight();
        return;
    }
private:
    unordered_set<string> myset; // Functions as visited
    vector<vector<int>> direction = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
};
