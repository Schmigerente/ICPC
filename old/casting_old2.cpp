#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
//using graph = vector<vector<ll>>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll t;
    cin >> t;

    for (ll c = 0; c < t; c++) {
        ll n;
        cin >> n;
        string row;
        cin >> row;

        ll blc = count(row.begin(), row.end(), 'B');
        ll wht = count(row.begin(), row.end(), 'W');
        char ctype = 'B';

        if (blc % 2 && wht % 2) {
            cout << "NO" << endl;
            continue;
        }

        if (blc % 2) {
            ctype = 'W';
        } else if (wht % 2) {
            ctype = 'B';
        } else {
            if (blc > wht) {
                ctype = 'W';
            } else {
                ctype = 'B';
            }
        }

        vector<ll> pmr;

        for(ll i = 0; i < n - 1; i++) {
            if (row[i] == ctype) {
                pmr.push_back(i);
                row[i + 1] = row[i + 1] == 'W' ? 'B' : 'W';
            }
        }

        cout << "YES" << endl << pmr.size() << endl;

        for (auto e : pmr) {
            cout << (e + 1) << " ";
        }
        cout << endl;
    }

    return 0;
}