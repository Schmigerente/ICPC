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

ll n;
ll maximum_flow;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    maximum_flow = 1000;

    ll cases;
    cin >> cases;

    for (ll c = 0; c < cases; c++) {

        ll a_case, b_case;
        cin >> a_case >> b_case;

        vector<ll> A;
        vector<ll> B;

        n = a_case + b_case + 2;

        loop (0, a_case) {
            ll t;
            cin >> t;
            A.push_back(t);
        }

        loop (0, b_case) {
            ll t;
            cin >> t;
            B.push_back(t);
        }

        capacity.resize(n);
        for (auto &e : capacity) {
            e.resize(n);
            fill(e.begin(), e.end(), 0);
        }

        adj.resize(n);
        for (auto &e : adj) {
            e.clear();
        }

        for (ll a = 1; a <= a_case; a++) {
            adj[0].push_back(a);
            adj[a].push_back(0);
            capacity[0][a] = 1;
        }

        for (ll b = 1; b <= b_case; b++) {

            ll b_access = a_case + b;

            adj[n-1].push_back(b_access);
            adj[b_access].push_back(n-1);
            capacity[b_access][n-1] = 1;
        }

        for (ll a = 0; a < a_case; a++) {
            for (ll b = 0; b < b_case; b++) {
                if (B[b] % A[a] == 0) {

                    ll a_access = a + 1;
                    ll b_access = a_case + b + 1;

                    adj[a_access].push_back(b_access);
                    adj[b_access].push_back(a_access);
                    capacity[a_access][b_access] = 1;
                }
            }
        }

        /*
        ll cc = 0;
        cout << "    0 1 2 3 4 5 6 7 8 9" << endl;
        cout << "    - - - - - - - - - -" << endl;
        for (auto &v : capacity) {
            cout << c++ << " | ";
            for (auto e : v) {
                cout << e << " ";
            }
            cout << endl;
        }
        */

        cout << maxflow(0, n-1) << endl;

    }

    return 0;

}