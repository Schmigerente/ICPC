#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

struct p
{
    ll a = 0, b = 0, c = 0;
    p() {

    }

    p(ll l, ll u, ll p)
    {
        a = l;
        b = u;
        c = p;
    }
};

vector<p> in;


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
        return m1.a < m2.a;
    });

    auto cmp = [](const p &m1, const p &m2) {if (m1.b == m2.b){return m1.a < m2.a; } return m1.b > m2.b;};
    priority_queue<p, vector<p>, decltype(cmp)> p_set(cmp);

    int index = 0;

    string s = "";

    for (int i = 0; i < c; i++) {
        while (index < c && in[index].a == i + 1)
        {
            p_set.push(in[index++]);
        }
        auto elem = p_set.top();
        p_set.pop();
        cout << elem.c + 1 << " ";
    }

    return 0;
}