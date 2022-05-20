#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for(ll i = l; i < u; i++)
#define rev(l, u) for(ll i = u - 1; i >= u; i--)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;

vector<ll> fun;
    graph tree;

tuple<ll, ll> trace(ll index) {
    if (tree[index].empty()) {
        return {fun[index], 0};
    } else {
        ll withsum = fun[index], withoutsum = 0;
        for (ll l : tree[index]) {
            tuple<ll, ll> t = trace(l);
            withsum += get<1>(t);
            withoutsum += get<0>(t);
        }
        return {max(withsum, withoutsum), withoutsum};
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll colleagues;
    cin >> colleagues;


    it (0, colleagues) {
        ll l;
        cin >> l;
        fun.push_back(l);
    } 

    it (1 ,colleagues) {
        ll l;
        cin >> l;
        l--;
        tree[l].push_back(i);
    }

    tuple<ll, ll> r = trace(0);
    cout << max(get<0>(r), get<1>(r)) << endl;

    return 0;
}