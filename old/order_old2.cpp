#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

struct p
{
    ll a = 0, b = 0, c = 0, d = 0;
    p() {

    }

    p(ll l, ll u, ll p)
    {
        a = l;
        b = u;
        c = p + 1;
        d = a - b;
    }
};

vector<p> in;
p out[300000];

int first_free(int index) {
    while (out[index].a != 0) {
        index++;
    }
    return index;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    ll c;
    cin >> c;

    int a, b;
    cin >> a >> b;
    for (int i = 0; i < c; i++)
    {
        in.push_back(p(a, b, i));
    }

    auto start = high_resolution_clock::now();
    sort(in.begin(), in.end(), [](const p &m1, const p &m2) {
        if (m1.d == m2.d)
        {   
            return m1.a > m2.a;
        }
        return m1.d < m2.d;
    });
    cout << duration_cast<microseconds>(high_resolution_clock::now() - start).count() << endl;

    start = high_resolution_clock::now();
    while (!in.empty())
    {
        auto elem = in.back();
        out[first_free(elem.a - 1)] = elem;
        in.pop_back();
    }
    cout << duration_cast<microseconds>(high_resolution_clock::now() - start).count() << endl;

    for (int i = 0; i < c; i++)
    {
        //cout << out[i].c << " ";
    }

    return 0;
}