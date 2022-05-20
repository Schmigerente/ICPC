#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for(ll i = l; i < u; i++)
#define rev(l, u) for(ll i = u - 1; i >= u; i--)

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    ll count, x, y, buffer;
    while(cin >> x) {
        cin >> y >> count;
        it (0, count) {
            cin >> buffer;
            cout << (buffer < 3 || ((x%buffer==0&&(y-2)%buffer==0)||((x-2)%buffer==0&&y%buffer==0)||((x-1)%buffer==0&&(y-1)%buffer==0)) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}