#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for(ll i = l; i < u; i++)
#define rev(l, u) for(ll i = u - 1; i >= u; i--)

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll size;
    cin >> size;
    vector<ll> blocks;

    it (0, size) {
        ll buffer;
        cin >> buffer;
        blocks.push_back(buffer);
    }

    sort(blocks.begin(), blocks.end());

    it (0, size) {
        cout << blocks[i] << " ";
    }
    cout << endl;
   
    return 0;
}