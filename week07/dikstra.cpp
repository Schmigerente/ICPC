#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define loop(l, u) for(ll i = l; i < u; i++)
#define rloop(l, u) for(ll i = u - 1; i >= l; i--)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<tuple<ll, ll>>>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
   
    ll cases;
    cin >> cases;

    loop (0, cases) {
        ll cities, streets;
        cin >> cities >> streets;

        wgraph g;

        for (int j = 0; j < streets; j++) {
            ll start, end, dist;
            cin >> start >> end >> dist;
            g[start].push_back({end, dist});
        }



        ll d [cities];
        priority_queue<tuple<ll, ll>> pq;

        d[0] = 0;
        for (ll j = 1; j < cities; j++) {
            d[j] = 9000000000000000;
        }

        pq.push({0, 0});

        while (!pq.empty()) {
            tuple<ll, ll> t = pq.top();
            pq.pop();
            if (get<0>(t) == d[get<1>(t)]) {
                vector<tuple<ll, ll>> adjacents = g[get<1>(t)];
                for (ll j = 0; j < adjacents.size(); j++) {
                    tuple<ll, ll> v = adjacents[j];
                    if (d[get<0>(v)] > d[get<1>(t)] + get<1>(v)) {
                        d[get<0>(v)] = d[get<1>(t)] + get<1>(v);
                        pq.push({d[get<0>(v)], get<0>(v)});
                    }
                }
            }
        }

        for (ll j = 0; j < cities; j++) {
            cout << d[j] << endl;
        }

    }

    return 0;
}