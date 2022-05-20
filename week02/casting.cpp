#include <bits/stdc++.h>

#define endl "\n"

using namespace std;
using ll = long long;
//using graph = vector<vector<ll>>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll cs;
    cin >> cs;

    for (ll c = 0; c < cs; c++)
    {
        ll lnt;
        string in;
        cin >> lnt >> in;

        ll blk = count(in.begin(), in.end(), 'B');
        ll wht = count(in.begin(), in.end(), 'W');

        if (wht % 2 && blk % 2)
        {
            cout << "NO" << endl;
            continue;
        }

        char chr = 'B';

        if (wht % 2)
        {
            chr = 'B';
        }
        else if (blk % 2)
        {
            chr = 'W';
        }
        else {
            if (blk > wht)
            {
                chr = 'W';
            }
            else
            {
                chr = 'B';
            }
        }

        vector<ll> pmr;
        for (ll i = 0; i < lnt - 1; i++)
        {
            if (in[i] == chr)
            {
                pmr.push_back(i);
                in[i + 1] = in[i + 1] == 'W' ? 'B' : 'W';
            }
        }

        cout << "YES" << endl
             << pmr.size() << endl;
        for (auto e : pmr)
        {
            cout << (e + 1) << " ";
        }
        cout << endl;
    }

    return 0;
}