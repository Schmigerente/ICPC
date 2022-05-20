#include <bits/stdc++.h>

#define endl "\n"

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

ll points;

#define mmod(e) (((e) + points) % points)
#define mid(a, b) ((a) + mmod(b - a) / 2)

int ask(ll a, ll b) {
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

ll calc(ll a, ll b, ll c) {
    if (mmod(b - a) == 1) {
        if (mmod(c - b) == 1) {
            return b;
        }
        ll bc = mid(b, c);
        if (ask(b, bc)) {
            return calc(b, bc, c);
        } else {
            return calc(a, b, bc);
        }
    }

    if (mmod(c - b) == 1) {
        ll ab = mid(a, b);
        if (ask(b, ab)) {
            return calc(a, ab, b);
        } else {
            return calc(ab, b, c);
        }
    }

    ll ab = mid(a, b);
    ll bc = mid(b, c);

    if (ask(b, ab)) {
        return calc(a, ab, b);
    }
    if (ask(b, bc)) {
        return calc(b, bc, c);
    }
    return calc(ab, b, bc);  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    ll a,b,c;
    cin >> points;

    a = 0;
    b = points/3;
    c = b*2;

    ll ans;

    if (ask(a,b)) {
        if (ask(b,c)) {
            ans = calc(b, c, a);
        } else {
            ans = calc(a, b, c);
        }
    } else {
        if (ask(a,c)) {
            ans = calc(b, c, a);
        } else {
            ans = calc(c, a, b);
        }
    }
    cout << "! " << ans << endl; 
    return 0;
}