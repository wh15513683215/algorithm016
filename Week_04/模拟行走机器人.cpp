class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int direx[] = {0, 1, 0, -1};
    int direy[] = {1, 0, -1, 0};
    int curx = 0, cury = 0, dir = 0, ans = 0;
    int len = commands.size();
    set<pair<int, int> > obstacleSet;


    for (int i = 0; i < obstacles.size(); ++i) 
    obstacleSet.insert(make_pair(obstacles[i][0],obstacles
    [i][1]));


    for (int i = 0; i < len; i++) {
    if (commands[i] == -1) {
        dir = (dir + 1) % 4;
    } else if (commands[i] == -2) {
        dir = (dir + 3) % 4;
    } else {
        for (int j = 0; j < commands[i]; j++) {
            int nx = curx + direx[dir];
            int ny = cury + direy[dir];
            if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
                curx = nx;
                cury = ny;
                ans = max(ans, curx*curx + cury*cury);
            } else {
                break;
            }
        }
    }
 }
    return ans;
    }
}; //O(n)O(n) 