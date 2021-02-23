/*

On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Note:

1 <= grid.length * grid[0].length <= 20
*/

class Solution {
public:
    int ret = 0, n = 0, m = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr = 0, sc = 0, cnt = 0;
        n = grid.size(), m = grid[0].size();
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 1) {
                    sr = r; sc = c;
                }   
                if (grid[r][c] >= 0)  cnt++; // count starting point as well as the ending point
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        backtrack(sr, sc, visited, grid, cnt);
        return ret;
    }
    void backtrack(int r, int c, vector<vector<bool>> &visited, vector<vector<int>>& grid, int remains) {
        static vector<pair<int, int>> directions = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
        // remains == 1 because we need to exclude the ending point
        if (grid[r][c] == 2 && remains == 1) {
            ret++;
            return ; // return right away because the should be the ending sqaure, no more square after this 
        }
        visited[r][c] = true;
        for (auto &[dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] != -1) 
                backtrack(nr, nc, visited, grid, remains - 1);
        }
        visited[r][c] = false; // allow other path to bypass this square later
    }
};