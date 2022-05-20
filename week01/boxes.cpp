#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int boxes[500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int box_amount;
    cin >> box_amount;
    for (int i = 0; i < box_amount; i++) {
        cin >> boxes[i];
    }

    sort(boxes, boxes + box_amount);

    int visible = box_amount;
    int i = visible - 1;
    int j = visible - 2;

    while (j >= 0) {
        if (boxes[j] * 2 <= boxes[i]) {
            i--;
            visible--;
        }
        j--;
    }

    cout << visible << endl;
    return 0;
}