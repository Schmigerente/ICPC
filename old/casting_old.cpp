#include <bits/stdc++.h>

#define endl "\n"

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int cases;
    cin >> cases;

    for (int c = 0; c < cases; c++)
    {
        int length;
        string input;
        cin >> length;
        cin >> input;
        int black = 0;
        int white = 0;
        for (int i = 0; i < length; i++)
        {
            if (input[i] == 'W')
            {
                white++;
            }
            else
            {
                black++;
            }
        }

        if (white % 2 == 1 && black % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        char chr;

        if (black > white)
        {
            chr = 'W';
        }
        else
        {
            chr = 'B';
        }

        if (white % 2 == 1)
        {
            chr = 'B';
        }

        if (black % 2 == 1)
        {
            chr = 'W';
        }

        int perms = 0;
        bool changed = false;
        string aws;
        for (int i = 0; i < length; i++)
        {
            bool b;
            if ((b = (input[i] == chr)) ^ changed)
            {
                aws += to_string(i + 1) + " ";
                perms++;
            }
            changed = (changed ^ b);
        }

        cout << "YES\n"
             << perms << endl
             << aws << endl;
    }

    return 0;
}