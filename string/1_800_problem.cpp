// namespace std have been included for this problem.
#include <vector>
#include <iostream>

using namespace std;
// Add any helper functions(if needed) above.
void permutation_helper(int row, int col, vector<vector<char> *> &from, string str, vector<string> &ret) {
    if (row >= from.size()) {
        ret.push_back(str);
        return ;
    }
    for(; col < from[row]->size(); col++) {
        str += from[row]->at(col);
        permutation_helper(row + 1, 0, from, str, ret);
        str = str.substr(0, str.length() - 1);
    }
}

vector<string> get_strings_from_nums(string digits) 
{
    vector<vector<char>> mapping = {
        {}, // 0  
        {}, // 1
        {'a', 'b', 'c'}, // 2 
        {'d', 'e', 'f'}, // 3
        {'g', 'h', 'i'}, // 4
        {'j', 'k', 'l'}, // 5
        {'m', 'n', 'o'}, // 6
        {'p', 'q', 'r', 's'}, // 7
        {'t', 'u', 'v'}, // 8
        {'w', 'x', 'y', 'z'}, // 9
    };
    vector<string> ret;
    vector<vector<char> *> from;
    for (char x: digits)
        from.push_back(&mapping[x - '0']);
    permutation_helper(0, 0, from, "", ret);
    return ret;
}

int main(){
    auto strings = get_strings_from_nums("232");
    for (auto s: strings)
        cout << s << endl;
    return 0;
}