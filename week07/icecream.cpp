#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define loop(l, u) for (ll i = l; i < u; i++)
#define rloop(l, u) for (ll i = u - 1; i >= l; i--)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<pair<ll, ll>>>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll rooms, cons;
    cin >> rooms >> cons;

    auto cmp = [](pair<ll, ll> left, pair<ll, ll> right) {return left.second > right.second;};

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> pq(cmp);
    wgraph g;
    map<ll, bool> visited;

    for (ll j = 0; j < rooms; j++) {
        ll dist;
        cin >> dist;
        pq.push({j, dist});
    }

    for (ll j = 0; j < cons; j++) {
            ll start, end, dist;
            cin >> start >> end >> dist;
            g[start].push_back({end, dist});
            g[end].push_back({start, dist});
        }

    ll costs = 0;

    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        if (visited[t.first])
        {
            continue;
        }
        visited[t.first] = true;
        costs += t.second;
        vector<pair<ll, ll>> v = g[t.first];
        for (ll j = 0; j < v.size(); j++)
        {
            pair<ll, ll> p = v[j];
            if (!visited[p.first])
            {
                pq.push(p);
            }
        }
    }

    cout << costs << endl;

    return 0;
}