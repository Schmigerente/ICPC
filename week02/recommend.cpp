#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<ll>>;

ll in[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
    ll dif, num;

    cin >> num >> dif;

    for (ll i = 0; i < num; i++) {
        cin >> in[i];
    }

    sort(in, in + num);

    ll i = num - 1;

    ll difsum = 0;
    ll amount = 0;

    while (difsum + in[i] >= (amount + 1)*dif && i >= 0) {
        difsum += in[i];
        amount++;
        i--;
    }

    cout << endl << amount << endl;

    return 0;
}