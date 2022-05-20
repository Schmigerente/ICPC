#include <bits/stdc++.h>

#define endl "\n"
#define print(a) cout << (a) << endl
#define caseloop  \
    ll cases;     \
    cin >> cases; \
    for (ll current_case = 0; current_case < cases; current_case++)
#define mod(a, b) ((a % b + b) % b)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<pair<ll, ll>>>;

ll pw(ll a, ll b)
{
    return b >= 1 ? a * pw(a, b - 1) : 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll n, q, log2n;
    cin >> n >> q;
    log2n = (ll)(log2(n));

    vector<array<ull, 19>> node;
    node.resize(n);

    for (ll i = 0; i < n; i++)
    {
        string in;
        cin >> in;
        node[i][0] = stoull(in, nullptr, 16);
    }

    for (ll b = 1; b <= log2n; b++)
    {
        for (ll i = 0; i < n; i++)
        {
            node[i][b] = node[i][b - 1] ^ node[(i + pw(2, b - 1)) % n][b - 1];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll b = 0; b <= 18; b++)
        {
            //cout << node[i][b] << " ";
        }
        //cout << endl;
    }

    for (ll i = 0; i < q; i++)
    {
        ll start, end, dist;
        ull out = 0;
        cin >> start >> end;
        dist = mod(end - start, n);
        ll p = start - 1;
        for (int j = 18; j >= 0; j--)
        {
            ll pow = pw(2, j);
            if (dist >= pow)
            {   
                dist -= pow;
                out = out ^ node[p][j];
                p = (p + pow) % n;
            }
        }
        cout << out << endl;
    }
    return 0;
}