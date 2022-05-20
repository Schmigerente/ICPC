#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for (ll i = l; i < u; i++)

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

void fastscan(ll &number)
{
    bool negative = false;
    register int c;
  
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll amount, cur, c = 0;
    ll ct[] = {0, 0};

    fastscan(amount);

    it(0, amount) {
        fastscan(cur);
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