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

    ll cases;
    cin >> cases;

    loop (0, cases) {
        ll number;
        cin >> number;
        //number = i+1;
        ll res = number;
        ll pre = 1;
        ll pow = 0;
        vector<ll> pows;
        pows.clear();
        while (pow <= number) {
            pow = pre*5+1;
            pows.push_back(pow);
            pre = pow;
        }
        for (int j = pows.size()-2; j >= 0; j--) {
            res -= (res)/(pows[j]);
        }
        //cout << i+1 << " " << res*5 << endl;
        cout << res*5 << endl;
    }

    return 0;
}