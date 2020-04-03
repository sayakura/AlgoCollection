#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <utility>
#include <set>

using namespace std;

struct Cell {
  int r, c;
  int cost;
  Cell(int r, int c, int cost) : r(r), c(c), cost(cost) {}
};

struct Map {
  vector<string> map;
  int height;
  int width;
};

bool operator < (const Cell &l, const Cell &r) {
  if (l.cost == r.cost) {
    if (l.r != r.r) 
      return l.r < r.r;
    else
      return l.c < r.c;
  }
  return l.cost < r.cost;
}

vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
      tokens.push_back(token);
   return tokens;
}

bool isValid(Map &map, int r, int c){
    if (r >= 0 && r < map.height && c >= 0 && c < map.width)
      return true;
    return false;
} 

int calCost(Map &map, Cell &currentCell, int newRow, int newCol) {
    int curN = map.map[currentCell.r][currentCell.c];
    int targ = map.map[newRow][newCol];
    return abs(curN - targ);
}

// Cell pop_min(vector<Cell> &list) {
//     Cell ret = list[0];
//     int index = 0;
//     for (int i = 1; i < list.size(); i++) {
//         if (list[i].cost < ret.cost) {
//             ret = list[i];
//             index = i;
//         }
//     }
//     list.erase(list.begin() + index);
//     return ret;
// }

// void remove_cell(vector<Cell> &list, Cell c) {

//     int index = 0;
//     for (int i = 0; i < list.size(); i++) {
//         if (list[i].cost == c.cost && list[i].c == c.c
//             && list[i].r == c.r) 
//         {
//             index = i;
//             break ;
//         }
//     }
//     list.erase(list.begin() + index);
// }

int dijkstra(Map &map) {
  vector<vector<int> > costs(map.height, vector<int>(map.width, numeric_limits<int>::max()));
  const vector<pair<int, int> > directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; 
  set<Cell> openList; // list of all the cell that's going to explore
  Cell curr = Cell(0, 0, 0);
  int ccost = 0;
  
  openList.insert(curr);
  costs[0][0] = ccost;
  while (!openList.empty()) {
    //curr = pop_min(openList);
    curr = *openList.begin();
    openList.erase(openList.begin());
    // cout << curr.r << " " << curr.c << endl;
    for (auto d : directions) {
      int newRow = curr.r + d.first;
      int newCol = curr.c + d.second;
      if (!isValid(map, newRow, newCol))
        continue ;
      int ccost = calCost(map, curr, newRow, newCol);
      if (costs[newRow][newCol] > costs[curr.r][curr.c] + ccost) {
        if (costs[newRow][newCol] != numeric_limits<int>::max()) 
            openList.erase(openList.find(Cell(newRow, newCol, costs[newRow][newCol]))) ;
        //remove_cell(openList, Cell(newRow, newCol, costs[newRow][newCol]));
        costs[newRow][newCol] = costs[curr.r][curr.c] + ccost;
        openList.insert(Cell(newRow, newCol, costs[newRow][newCol]));
      }
    }
  }
  return costs[map.height - 1][map.width - 1];
}


int path_finder(std::string maze)
{
  vector<string> _m = split(maze, '\n');
  Map m;
  m.map = _m;
  m.height = _m.size();
  m.width = _m[0].size();
  if (m.height == 1)
    return 0;
  return dijkstra(m);
}

int main() {
    std::string s1 = 
    "000\n"
    "000\n"
    "000";
        
    std::string s2 = 	
    "010\n"
    "010\n"
    "010";

    std::string s3 = 	
    "010\n"
    "101\n"
    "010";

    std::string s4 = 	
    "0707\n"
    "7070\n"
    "0707\n"
    "7070";

    std::string s5 = 
    "700000\n"
    "077770\n"
    "077770\n"
    "077770\n"
    "077770\n"
    "000007";

    std::string s6 = 	
    "777000\n"
    "007000\n"
    "007000\n"
    "007000\n"
    "007000\n"
    "007777";

    std::string s7 = 	
    "000000\n"
    "000000\n"
    "000000\n"
    "000010\n"
    "000109\n"
    "001010";	

    cout << path_finder(s1) << endl;
    cout << path_finder(s2) << endl;
    cout << path_finder(s3) << endl;
    cout << path_finder(s4) << endl;
    cout << path_finder(s5) << endl;
    cout << path_finder(s6) << endl;
    cout << path_finder(s7) << endl;

    return 0;
}