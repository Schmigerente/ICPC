#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for (ll i = l; i < u; i++)

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll amount, cur, c = 0;
    ll ct[] = {0, 0};

    cin >> amount;

    it(0, amount) {
        cin >> cur;
        ct[i % 2] += cur;
        if (ct[i%2] < ct[(i + 1) % 2]) {
            c += ct[(i + 1) % 2];
            ct[0] = 0;
            ct[1] = 0;
        }
    }

    cout << (c + max(ct[0], ct[1])) << endl;

    return 0;
}