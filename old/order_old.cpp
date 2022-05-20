#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

struct p
{
    ll a, b, c;
    p(ll l, ll u, ll p)
    {
        a = l;
        b = u;
        c = p + 1;
    }
};

vector<p> in;
vector<p> out;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    ll c;
    cin >> c;

    int a, b;
    for (int i = 0; i < c; i++)
    {
        cin >> a >> b;
        in.push_back(p(a, b, i));
    }

    sort(in.begin(), in.end(), [](const p &m1, const p &m2) {
        if (m1.a == m2.a)
        {
            return m1.b < m2.b;
        }
        return m1.a < m2.a;
    });

    int i = 1;
    while (!in.empty())
    {
        out.push_back(in[0]);
        in.erase(in.begin());
        auto ptr1 = lower_bound(in.begin(), in.end(), p(i++, 0, 0), [](const p &m1, const p &m2) { return m1.a < m2.a; });
        auto ptr2 = lower_bound(in.begin(), in.end(), p(i+1, 0, 0), [](const p &m1, const p &m2) { return m1.a < m2.a; });
        if (ptr1 != in.end())
        {
            sort(in.begin(), ptr2, [](const p &m1, const p &m2) {
                if (m1.b == m2.b)
                {
                    return m1.a < m2.a;
                }
                return m1.b < m2.b;
            });
        }
    }

    for (p elem : out)
    {
        cout << elem.c << " ";
    }

    return 0;
}