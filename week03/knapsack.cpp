#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for (ll i = l; i < u; i++)

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

void fastscan(ll &number) {bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}

ll items[3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll amount, capacity;
    fastscan(amount);
    fastscan(capacity);
    ll dist = capacity;

    it (0, amount) {
        ll d;
        fastscan(d);
        items[d-1]++;
    }

    if (items[2]*3 <= dist) {
        dist -= items[2]*3;
    } else {
        dist = dist%3;
    }

    ll remaining = 0;
    if (items[1]*2 <= dist) {
        dist -= items[1]*2;

    } else {
        remaining = items[1] - dist/2;
        dist = dist%2;
    }


    if (items[0] <= dist) {
        dist -= items[0];
    } else {
        dist = 0;
    }

    if (items[2] > 0 && dist == 1 && remaining >= 2) {
        dist--;
    }

    cout << capacity - dist << endl;

    return 0;
}