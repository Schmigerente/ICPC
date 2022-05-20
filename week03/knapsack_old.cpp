#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for (ll i = l; i < u; i++)
#define read(arr, lim)           \
    for (ll i = 0; i < lim; i++) \
    {                            \
        cin >> arr[i];           \
    }
#define prints(arr, lim)         \
    for (ll i = 0; i < lim; i++) \
    {                            \
        cout << arr[i] << " ";   \
    }
#define printl(arr, lim)         \
    for (ll i = 0; i < lim; i++) \
    {                            \
        cout << arr[i] << endl;  \
    }

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

ll items[200000];
ll f[200000][4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll amount, capacity;
    cin >> amount >> capacity;

    read(items, amount);

    for (int64_t i = 1; i <= amount; ++i)
    {
        for (int64_t j = 1; j <= capacity; ++j)
        {
            f[i][j % 4] = f[i - 1][j % 4];
            if (j >= items[i])
            {
                f[i][j % 4] = max(f[i - 1][j % 4], f[i - 1][(j - items[i]) % 4] + items[i]);
            }
        }
    }
    cout << f[amount - 1][(capacity - 1) % 4];
    return 0;
}