#include <bits/stdc++.h>

#define endl        "\n"
#define print(a)    cout << (a) << endl

#define all(e)      (e).begin(), (e).end()
#define loop(l, u)  for(ll i = l; i < u; i++)
#define rloop(l, u) for(ll i = u - 1; i >= l; i--)
#define caseloop    ll cases; \
                    cin >> cases; \
                    for(ll current_case = 0; current_case < cases; current_case++) \

#define mod(a, b)   ((a%b+b)%b)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<pair<ll, ll>>>;

using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

struct point {
    ll x, y;
    point (ll a, ll b) {
        x = a;
        y = b;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    vector<point> points;
    deque<point> active;

    caseloop {
        ll x, y;
        cin >> x >> y;
        points.push_back(point(x, y));
    }

    sort(all(points), [ ]( const auto& lhs, const auto& rhs ){return lhs.x < rhs.x;});

    ll d = 5000000000000;

    for (auto it = points.begin(); it != points.end(); it++) {
        while (!active.empty() && (it->x - active.front().x) > d) {
            active.pop_front();
        }
        for (auto it2 = active.cbegin(); it2 != active.cend() && it2->y-it->y <= d; it2++) {
            d = min(d,((it->x-it2->x)*(it->x-it2->x)+(it->y-it2->y)*(it->y-it2->y)));
        }
        active.push_back(*it);
    }

    cout << d << endl;

    return 0;
}