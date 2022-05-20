#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for (ll i = l; i < u; i++)
#define rev(l, u) for (ll i = u - 1; i >= u; i--)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll cases;
    cin >> cases;
    it(0, cases)
    {
        ll n;
        cin >> n;

        if (n == 2)
        {
            cout << "impossible" << endl;
            continue;
        }
        ll q = 2 - (n % 2);
        ll c = q;
        it(0, n)
        {
            it(0, n)
            {
                cout << c << " ";
                c = (c >= n * n ? q%2+1 : c + 2);
            }
            cout << endl;
        }
    }
    return 0;
}