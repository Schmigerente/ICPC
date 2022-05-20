#include <bits/stdc++.h>

#define endl "\n"
#define mod(a,b) ((a%b)+b)%b
#define all(e) (e).begin(), (e).end()
#define loop(l, u) for(ll i = l; i < u; i++)
#define rloop(l, u) for(ll i = u - 1; i >= l; i--)
#define min(a, b)   ((a)<(b)?(a):(b))

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<pair<ll, ll>>>;

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of
    // recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll cases;
    cin >> cases;

    loop (0, cases) {
        ll k, c, x, y;
        cin >> k >> c;

        if (k == 1000000000 && c == 1) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        if (c == 1) {
            cout << k+1 << endl;
            continue;
        }

        if (k == 1) {
            cout << 1 << endl;
            continue;
        }

        ll gcd = gcdExtended(k, c, &x, &y);
        if (gcd != 1) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << mod(y/gcd, k) << endl;
    }
   
    return 0;
}