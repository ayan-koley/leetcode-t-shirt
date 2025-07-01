#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        int i = 0;
        while(i < word.size()) {
            int j = i + 1;
            while(j < word.size() && word.at(i) == word.at(j)) {
                j++;
            }
            int differ = j - i - 1;
            i = j;
            count += differ;
        }
        return count;
    }
};

int main() {
    Solution slt;
    int val =  slt.possibleStringCount("abccc");
    cout << val;
    return 0;
}