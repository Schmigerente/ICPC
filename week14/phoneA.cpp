#include <bits/stdc++.h>

#define endl        "\n"
#define print(a)    cout << (a) << endl
#define caseloop    ll cases; \
                    cin >> cases; \
                    for(ll current_case = 0; current_case < cases; current_case++)
#define mod(a, b)   ((a%b+b)%b)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;
using wgraph = map<ll, vector<pair<ll, ll>>>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll num;
    cin >> num;

    ll val = num;

    val = val/100000;

    ll digit = val%10;

    chrono::time_point<chrono::high_resolution_clock> time = chrono::high_resolution_clock().now();
    time += chrono::milliseconds(digit*100);

    while(chrono::high_resolution_clock().now() < time) {

    }

    cout << num << endl;

    
    return 0;
}