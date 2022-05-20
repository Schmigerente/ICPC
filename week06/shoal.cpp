#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for(ll i = l; i < u; i++)
#define rev(l, u) for(ll i = u - 1; i >= u; i--)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;

struct edge {
    ll s,t;
    edge(ll a, ll b) {
        s = a;
        t = b;
    }
};



graph g;
map<ll, bool> found;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
   
    ll nodes, edges;
    cin >> nodes >> edges; 

    it (0, edges) {
        ll start, end;
        cin >> start >> end;
        g[start].push_back(end);
        g[end].push_back(start);
    }

    queue<ll> q;
    q.push(0);
    found[0] = true;

    while (q.size() > 0) {
        ll i = q.front();
        q.pop();
        for(ll l : g[i]) {
            if(!found[l]) {
                q.push(l);
                found[l] = true;
            }
        }
    }

    string out = "YES";
    it (0, nodes) {
        if (found[i] == false) {
            out = "NO";
            break;
        }
    }

    cout << out << endl;

    return 0;
}