#include <bits/stdc++.h>

#define endl        "\n"
#define print(a)    cout << (a) << endl

#define all(e)      (e).begin(), (e).end()
#define loop(l, u)  for(ll i = l; i < u; i++)
#define rloop(l, u) for(ll i = u - 1; i >= l; i--)

#define min(a, b)   ((a)<(b)?(a):(b))
#define mod(a, b)   ((a%b+b)%b)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<pair<ll, ll>>>;

ll factorial[100000];
ll m = 1000000007;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll inverse(ll n) {
    return binpow(n, m-2);
}

ll binomial_coefficient(ll n, ll k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    factorial[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }

    print("2");

    ll cases;
    cin >> cases;

    loop(0, cases) {
        ll lower_bound, upper_bound, p;
        cin >> lower_bound >> upper_bound >> p;

        if (lower_bound == upper_bound || p == 2) {
            cout << "1" << endl;
            continue;
        }

        ll n = upper_bound-lower_bound+1;
        ll k =  p-2;

        cout << binomial_coefficient(n+k-1,n-1) << endl;


    }


    //binomialkoeffizienten
 
    return 0;
}