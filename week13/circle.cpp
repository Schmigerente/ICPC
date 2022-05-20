#include <bits/stdc++.h>

#define endl        "\n"
#define print(a)    cout << (a) << endl

#define all(e)      (e).begin(), (e).end()
#define loop(l, u)  for(ll i = l; i < u; i++)
#define rloop(l, u) for(ll i = u - 1; i >= l; i--)
#define caseloop    ll cases; \
                    cin >> cases; \
                    for(ll current_case = 0; current_case < cases; current_case++) \

#define min(a, b)   ((a)<(b)?(a):(b))
#define mod(a, b)   ((a%b+b)%b)

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

    caseloop {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        ll dist_sq = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

        if (min(r1, r2) == 0) {
            if (max(r1*r1, r2*r2) == dist_sq) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }         
            continue;
        }

        if (dist_sq == 0 && r1 == r2) {
            cout << "oo" << endl;
            continue;
        }

        ll rad_sq = (r1+r2)*(r1+r2);
        ll rad_sub_sq = (r1-r2)*(r1-r2);

        if (dist_sq == rad_sq || dist_sq == rad_sub_sq) {
            cout << 1 << endl;
            continue;
        }
        
        if (dist_sq > rad_sq || dist_sq < rad_sub_sq) {
            cout << 0 << endl;
            continue;  
        }

        cout << 2 << endl;
    }

    return 0;
}