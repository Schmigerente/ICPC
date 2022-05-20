#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define min(a, b)   ((a)<(b)?(a):(b))
#define loop(l, u) for(ll i = l; i < u; i++)
#define rloop(l, u) for(ll i = u - 1; i >= l; i--)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<pair<ll, ll>>>;

ll maximum_flow;
ll n;
vector<vector<ll>> capacity;
vector<vector<ll>> adj;

ll bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, maximum_flow});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t) {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t) {
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;

    while ((new_flow = bfs(s, t, parent))) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll w, l;
    cin >> w >> l;
    maximum_flow = (1000 * 10000 * 5);

    n = w*2;

    // one for each stone + source + drain
    capacity.resize(w * 2);
    for (auto &e : capacity) {
        e.resize(w * 2);
    }
    adj.resize(w * 2);

    vector<ll> resilience;
    for (ll i = 0; i < w - 1; i++) {
        ll r;
        cin >> r;
        resilience.push_back(r);
    }

    for (ll i = 0; i < l; i++) {
        if (resilience[i] > 0) {
            adj[0].push_back(i*2+1);
            adj[i*2+1].push_back(0);
            capacity[0][i*2+1] = resilience[i];
        }
    }

    for (ll x = 0; x < w - 1; x++) {
        ll res = resilience[x];
        if (res == 0) continue;

        adj[x*2+1].push_back(x*2+2);
        adj[x*2+2].push_back(x*2+1);
        capacity[x*2+1][x*2+2] = res;

        for (ll i = x + 1; i < l + x + 1 && i < w; i++) {
            ll pos = (x+1)*2;
            ll offst = i*2 + 1;

            if (resilience[i] > 0) {
                adj[pos].push_back(offst);
                adj[offst].push_back(pos);
                capacity[pos][offst] = resilience[i];
            }

            if (i == w-1) {
                adj[pos].push_back(w*2-1);
                adj[w*2-1].push_back(pos);
                capacity[pos][w*2-1] = res;
            }
        }
    }

    cout << maxflow(0, w * 2 - 1) << endl;

    return 0;
}
