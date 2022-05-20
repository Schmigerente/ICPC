#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define loop(l, u) for(ll i = l; i < u; i++)
#define rloop(l, u) for(ll i = u - 1; i >= l; i--)

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

    auto cmp = [](pair<ll, ll> left, pair<ll, ll> right) {return left.second > right.second;};

    loop (0, cases) {
        ll cities, streets;
        cin >> cities >> streets;

        wgraph g;
        map<ll, bool> visited;

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> pq(cmp);

        for (int j = 0; j < streets; j++) {
            ll start, end, dist;
            cin >> start >> end >> dist;
            g[start].push_back({end, dist});
            g[end].push_back({start, dist});
        }

        ll currentMax = 0;
        ll c = 0;
        ll tv = ceil((cities - 1) * 0.75) + 1;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            if (visited[t.first]) {
                continue;
            }
            visited[t.first] = true;
            if (t.second > currentMax) {
                currentMax = t.second;
            } 
            if (++c >= tv) {
                break;
            }
            vector<pair<ll, ll>> v = g[t.first];
            for (ll j = 0; j < v.size(); j++) {
                pair<ll, ll> p = v[j];
                if (!visited[p.first]) {
                    pq.push(p);
                }
            }
        }

        cout << currentMax << endl;

    }

    return 0;
}