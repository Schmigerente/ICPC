#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define loop(l, u) for(ll i = l; i < u; i++)
#define rloop(l, u) for(ll i = u - 1; i >= l; i--)
#define min(a, b)   ((a)<(b)?(a):(b))

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<pair<ll, ll>>>;

ll lpf (ll num) {
long long maxPrime = -1;
    while (num % 2 == 0) {
        maxPrime = 2;
        num >>= 1;
    }
  
    for (int i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            maxPrime = i;
            num /= i;
        }
    }
  
    if (num > 2)
        maxPrime = num;
  
    return maxPrime;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll number;
    cin >> number;
    cout << lpf(number) << endl;


   
    return 0;
}