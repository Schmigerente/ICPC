#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define loop(l, u) for(ll i = l; i < u; i++)
#define rloop(l, u) for(ll i = u - 1; i >= l; i--)
#define min(a, b)   ((a)<(b)?(a):(b))

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<pair<ll, ll>>>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll w,h;
    cin >> w >> h;

    /*
    if (w <= 2 && h <= 2) {
        cout << (w%3 == h%3 ? 1 : 2) << endl;
        return 0;
    }
    if (w <= 3 && h <= 3) {
        cout << (abs(w-h) == 1 ? 1 : 2) << endl;
        return 0;
    }
    */
    cout << ((w+h)%3 == 0 ? 2 : 1) << endl;
    return 0;
}