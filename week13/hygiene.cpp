#include <bits/stdc++.h>

#define endl "\n"
#define print(a) cout << (a) << endl

#define all(e) (e).begin(), (e).end()
#define loop(l, u) for (ll i = l; i < u; i++)
#define rloop(l, u) for (ll i = u - 1; i >= l; i--)
#define caseloop  \
    ll cases;     \
    cin >> cases; \
    for (ll current_case = 0; current_case < cases; current_case++)

#define mod(a, b) ((a % b + b) % b)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<pair<ll, ll>>>;

#define px second
#define py first
typedef pair<ll, ll> pall;

int compare(pall a, pall b)
{
        return a.px<b.px;
}

ll sweep_line(vector<pall> points)
{
        ll n = points.size();
        sort(points.begin(), points.end(), compare);
        ll d=1000000000000ll;
        set<pall> box;
        box.insert(points[0]);
        ll left = 0;
        for (ll i=1;i<n;++i)
        {
            while (left<i && points[i].px-points[left].px > d)
                box.erase(points[left++]);
            for(auto it=box.lower_bound(make_pair(points[i].py-d, points[i].px-d));it!=box.end() && points[i].py+d>=it->py;it++)
                d = min(d, (points[i].py - it->py) * (points[i].py - it->py) + (points[i].px - it->px) * (points[i].px - it->px));
            box.insert(points[i]);
        }
        return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    vector<pall> points;

    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back(pall(x, y));
    }

    cout << sweep_line(points) << endl;

    return 0;
}
