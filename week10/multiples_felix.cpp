
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'
#define min(a, b)   ((a)<(b)?(a):(b))

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

ll maximum_flow;
ll n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

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

void connect(ll a, ll b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll t;
    cin >> t;
    for (ll ij = 0; ij < t; ij++) {
        ll nA, nB;
        cin >> nA >> nB;
        vector<ll> A(nA);
        vector<ll> B(nB);
        for (ll i = 0; i < nA; i++) {
            ll e;
            cin >> e;
            A[i] = e;
        }
        for (ll i = 0; i < nB; i++) {
            ll e;
            cin >> e;
            B[i] = e;
        }
        maximum_flow = (1000 * 10000 * 5);
        n = nA + nB + 2;
        ll i_drain = n - 1;
        ll i_source = n - 2;

        capacity.resize(n);
        for (auto &e : capacity) {
            e.resize(n);
            fill(e.begin(), e.end(), 0);
        }
        adj.resize(n);
        for (auto &e : adj) {
            e.clear();
        }

        // connect from source
        for (ll a = 0; a < nA; a++) {
            connect(i_source, a);
            capacity[i_source][a] = 1;
        }
        // connect to drain
        for (ll b = 0; b < nB; b++) {
            connect(b + nA, i_drain);
            capacity[b + nA][i_drain] = 1;
        }

        for (ll a = 0; a < nA; a++) {
            for (ll b = 0; b < nB; b++) {
                ll ib = nA + b;
                if ((B[b] % A[a]) == 0) {
                    connect(a, ib);
                    capacity[a][ib] = 1;
                }
            }
        }
        cout << maxflow(i_source, i_drain) << endl;
    }

    return 0;
}
