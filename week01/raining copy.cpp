#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <ostream>
#include <stdlib.h>

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        stack<int> stack;
        ll water = 0;
        string s;
        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '\\') {
                stack.push(j);
                continue;
            }
            if (s[j] == '/') {
                if (!stack.empty()) {
                    water += (j - stack.top());
                    stack.pop();
                }
            }
        }
        cout << water << endl;
    }
    return 0;
}