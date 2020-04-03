#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <queue>
#include <utility>

using namespace std;

struct Node {
    int r;
    int c;
    int pathCnt;
    float gCost;
    float hCost;
    float fCost;
};

vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
      tokens.push_back(token);
   return tokens;
}

bool isValid(vector<string> maze, int row, int col) {
    if (row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size())
        return false;
    if (maze[row][col] == 'W')
        return false;
    return true;
}

bool isDestination(vector<string> maze, int row, int col) {
    if (row == maze.size() - 1 && col == maze[0].size() - 1) 
        return true;
    return false;
}

Node pop_min(vector<Node> &list) {
    Node ret = list[0];
    int index = 0;
    for (int i = 1; i < list.size(); i++) {
        if (list[i].fCost < ret.fCost) {
            ret = list[i];
            index = i;
        }
    }
    list.erase(list.begin() + index);
    return ret;
}

int path_finder(string m) {
    vector<string> maze = split(m, '\n'); 
    int height = maze.size();
    int width = maze[0].size();
    vector<pair<int, int> > directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    
    Node dest;
    Node curr;

    dest.r = height - 1;
    dest.c = width - 1;
    if (!isValid(maze, dest.r, dest.c)) 
        return -1;
    curr.fCost = numeric_limits<float>::max();
    curr.gCost = numeric_limits<float>::max();
    curr.hCost = numeric_limits<float>::max();
    curr.pathCnt = 0;
    curr.r = 0;
    curr.c = 0;
    if (isDestination(maze, curr.r, curr.c))
        return 0;
    vector<vector<Node> > allMap(height, vector<Node>(width,  curr)); 
    vector<vector<bool> > closedMap(height, vector<bool>(width, false)); 
    
    curr.fCost = 0.0;
    curr.gCost = 0.0;
    curr.hCost = 0.0;
    vector<Node> openList;
    openList.emplace_back(curr);
    while (!openList.empty()) {
        curr = pop_min(openList);

        closedMap[curr.r][curr.c] = true;
        for (int i = 0; i < directions.size(); i++) {
            int newRow = curr.r + directions[i].first; 
            int newCol = curr.c + directions[i].second; 

            float gCost, hCost, fCost;
            if (isValid(maze, newRow, newCol)) {
                if (isDestination(maze, newRow, newCol)) 
                    return allMap[curr.r][curr.c].pathCnt + 1;
                else if (closedMap[newRow][newCol] == false) {
                  
                    gCost = curr.gCost + 1.0;
                    hCost = abs(newRow - dest.r) + 
                            abs(newCol - dest.c);
                    fCost = gCost + hCost;
                    if (allMap[newRow][newCol].fCost == numeric_limits<int>::max() ||
                        allMap[newRow][newCol].fCost > fCost) {
                            allMap[newRow][newCol].gCost = gCost;
                            allMap[newRow][newCol].hCost = hCost;
                            allMap[newRow][newCol].fCost = fCost;
                            allMap[newRow][newCol].pathCnt = curr.pathCnt + 1;
                            allMap[newRow][newCol].r = newRow;
                            allMap[newRow][newCol].c = newCol;
                            openList.push_back(allMap[newRow][newCol]);
                        } 
                }
            }
        }
    }
    return -1;
}

int main() {

    // string str = ".";
    // cout << path_finder(str) << endl;
    // string str2 = ".....\n..W..\n..W..\n..W..\n..W..";
    // cout << path_finder(str2) << endl;
    // /**
    //  * .W...W
    //  * .W.W.W
    //  * .W.W.W
    //  * .W.W.W
    //  * .W.W.W
    //  * ...W..
    //  */
    // string str3 =  ".W...W\n.W.W.W\n.W.W.W\n.W.W.W\n.W.W.W\n...W..";
    // cout << path_finder(str3) << endl;

/*
.............
WWWWWWWWWWWW.
.............
.WWWWWWWWWWWW
.............
WWWWWWWWWWWW.
...........W.
.WWWWWWWWWWWW
.............
WWWWWWWWWWWW.
.............
.WWWWWWWWWWWW
.............
.............
WWWWWWWWWWWW.
.............
.WWWWWWWWWWWW
.............
WWWWW.WWWWWW.
...........W.
.WWWWWWWWWWWW
.............
WWWWWWWWWWWW.
.............
.WWWWWWWWWWWW
.............
*/
    // string str4 = ".............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............";
    // cout << path_finder(str4) << endl;
    // string s5 = ".............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n...........W.\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWW.WWWWWW.\n...........W.\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............";
    // cout << path_finder(s5) << endl;

/*
.............0
WWWWWWWWWWWW.1
.............2
.WWWWWWWWWWWW3
.............4
WWWWW.WWWWWW.5
...........W.
.WWWWWWWWWWWW
.............
WWWWWWWWWWWW.
.............
.WWWWWWWWWWWW
.............
*/
    string s = ".............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWW.WWWWWW.\n...........W.\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............";
    cout << path_finder(s) << endl;
    return (1);

}