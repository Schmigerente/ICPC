#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int lowest = -1;

    int parts, budget, h, w, p, n;
    cin >> parts;
    cin >> budget;
    cin >> h;
    cin >> w;

    for (int i = 0; i < h; i++) {
        cin >> p;
        for (int j = 0; j < w; j++) {
            cin >> n;
            if (p * parts > budget) {
                continue;
            }
            if (parts > n) {
                continue;
            }
            if (p < lowest || lowest < 0) {
                lowest = p;
            }
        }
    }
    if (lowest == -1) {
        cout << "stay home";
    }
    else {
        cout << lowest*parts;
    }
}

