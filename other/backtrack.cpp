#include <vector>
#include <utility>
#include <iostream>
using namespace std;

vector<pair<int, int>> get_directions() {
  vector<pair<int, int>> directions;
  for (int i = - 1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i || j)
        directions.push_back({ i, j });
    }
  }
  return directions;
}

inline bool is_valid(const vector<vector<char> > &board,  vector<vector<bool>> &visited, int r, int c) {
  return  !(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) && !visited[r][c];
} 

bool star_platinum(const vector<vector<char> > &board, 
      vector<vector<bool>> &visited, int r, int c, int curLen, const string &word) {
  static vector<pair<int, int>> directions;

  visited[r][c] = true;
  if (directions.empty())
     directions = get_directions();
  if (curLen > word.length())
    return false;
  if (board[r][c] == word[word.length() - curLen]) {
    if (curLen == 1) 
      return true;
    for (auto d: directions) {
      if (is_valid(board, visited, r + d.first, c + d.second) 
        && star_platinum(board, visited, r + d.first, c + d.second, curLen - 1, word))
        return true;
    }
  }
  visited[r][c] = false;
  return false;
}

bool check_word(const vector<vector<char> > &board, const string &word)
{
  for (int r = 0; r < board.size(); r++) {
    for (int c = 0; c < board[0].size(); c++) {
      if (board[r][c] == word[0]) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        if (star_platinum(board, visited, r, c, word.length(), word))
          return true;
      }  
    }
  }
  return false;
}

int main() {
    vector<vector<char> > test_board = {{'E','A','R','A'},
                                            {'N','L','E','C'},
                                            {'I','A','I','S'},
                                            {'B','Y','O','R'} };
    cout << check_word(test_board, "CEREAL") << endl;
}
