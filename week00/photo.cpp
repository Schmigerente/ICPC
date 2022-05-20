
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct s {
    string name;
    int y,x;
    s(string n, int i, int j) {
        x = i;
        y = j;
        name = n;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    vector<s> names;

    string name;
    int x, y;
    
    while (cin >> name) {
        cin >> x;
        cin >> y;
        names.push_back(s(name, x, y));
    }
    
    sort(names.begin(), names.end(), [](const s& m1, const s& m2) {
        int s = m1.x * m2.y - m2.x * m1.y;
        if (s == 0) {
            return m1.x < m2.x;
        }
        return s < 0;
        });

    for (s v : names) {
        cout << v.name << "\n";
    }
}
