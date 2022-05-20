#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

struct point {
    ll x, y;
    point (ll a, ll b) {
        x = a;
        y = b;
    }
};

#define px second
#define py first
typedef pair<ll, ll> pairll;

int compare(pairll a, pairll b)
{
        return a.px<b.px;
}

double closest_pair(vector<pairll> pnts)
{
        ll n = pnts.size();
        sort(pnts.begin(), pnts.end(), compare);
        ll best=1000000000000ll;
        set<pairll> box;
        box.insert(pnts[0]);
        ll left = 0;
        for (ll i=1;i<n;++i)
        {
            while (left<i && pnts[i].px-pnts[left].px > best)
                box.erase(pnts[left++]);
            for(auto it=box.lower_bound(make_pair(pnts[i].py-best, pnts[i].px-best));it!=box.end() && pnts[i].py+best>=it->py;it++)
                best = min(best, (pnts[i].py - it->py) * (pnts[i].py - it->py) + (pnts[i].px - it->px) * (pnts[i].px - it->px));
            box.insert(pnts[i]);
        }
        return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    vector<pairll> points;

    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back(pairll(x, y));
    }

    cout << closest_pair(points) << endl;

    return 0;
}
