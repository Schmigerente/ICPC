#include <bits/stdc++.h>

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
    int c = 0;
    cin >> cases;

    while (cases > c++)
    {
        int set[5];

        cin >> set[0] >> set[1] >> set[2] >> set[3] >> set[4];

        sort(set, set + 5);

        bool found = false;

        do
        {

            int i = 0;
            ll res[81];
            res[i++] = ((((set[0] + set[1]) + set[2]) + set[3]) + set[4]);
            res[i++] = ((((set[0] + set[1]) + set[2]) + set[3]) - set[4]);
            res[i++] = ((((set[0] + set[1]) + set[2]) + set[3]) * set[4]);
            res[i++] = ((((set[0] + set[1]) + set[2]) - set[3]) + set[4]);
            res[i++] = ((((set[0] + set[1]) + set[2]) - set[3]) - set[4]);
            res[i++] = ((((set[0] + set[1]) + set[2]) - set[3]) * set[4]);
            res[i++] = ((((set[0] + set[1]) + set[2]) * set[3]) + set[4]);
            res[i++] = ((((set[0] + set[1]) + set[2]) * set[3]) - set[4]);
            res[i++] = ((((set[0] + set[1]) + set[2]) * set[3]) * set[4]);
            res[i++] = ((((set[0] + set[1]) - set[2]) + set[3]) + set[4]);
            res[i++] = ((((set[0] + set[1]) - set[2]) + set[3]) - set[4]);
            res[i++] = ((((set[0] + set[1]) - set[2]) + set[3]) * set[4]);
            res[i++] = ((((set[0] + set[1]) - set[2]) - set[3]) + set[4]);
            res[i++] = ((((set[0] + set[1]) - set[2]) - set[3]) - set[4]);
            res[i++] = ((((set[0] + set[1]) - set[2]) - set[3]) * set[4]);
            res[i++] = ((((set[0] + set[1]) - set[2]) * set[3]) + set[4]);
            res[i++] = ((((set[0] + set[1]) - set[2]) * set[3]) - set[4]);
            res[i++] = ((((set[0] + set[1]) - set[2]) * set[3]) * set[4]);
            res[i++] = ((((set[0] + set[1]) * set[2]) + set[3]) + set[4]);
            res[i++] = ((((set[0] + set[1]) * set[2]) + set[3]) - set[4]);
            res[i++] = ((((set[0] + set[1]) * set[2]) + set[3]) * set[4]);
            res[i++] = ((((set[0] + set[1]) * set[2]) - set[3]) + set[4]);
            res[i++] = ((((set[0] + set[1]) * set[2]) - set[3]) - set[4]);
            res[i++] = ((((set[0] + set[1]) * set[2]) - set[3]) * set[4]);
            res[i++] = ((((set[0] + set[1]) * set[2]) * set[3]) + set[4]);
            res[i++] = ((((set[0] + set[1]) * set[2]) * set[3]) - set[4]);
            res[i++] = ((((set[0] + set[1]) * set[2]) * set[3]) * set[4]);
            res[i++] = ((((set[0] - set[1]) + set[2]) + set[3]) + set[4]);
            res[i++] = ((((set[0] - set[1]) + set[2]) + set[3]) - set[4]);
            res[i++] = ((((set[0] - set[1]) + set[2]) + set[3]) * set[4]);
            res[i++] = ((((set[0] - set[1]) + set[2]) - set[3]) + set[4]);
            res[i++] = ((((set[0] - set[1]) + set[2]) - set[3]) - set[4]);
            res[i++] = ((((set[0] - set[1]) + set[2]) - set[3]) * set[4]);
            res[i++] = ((((set[0] - set[1]) + set[2]) * set[3]) + set[4]);
            res[i++] = ((((set[0] - set[1]) + set[2]) * set[3]) - set[4]);
            res[i++] = ((((set[0] - set[1]) + set[2]) * set[3]) * set[4]);
            res[i++] = ((((set[0] - set[1]) - set[2]) + set[3]) + set[4]);
            res[i++] = ((((set[0] - set[1]) - set[2]) + set[3]) - set[4]);
            res[i++] = ((((set[0] - set[1]) - set[2]) + set[3]) * set[4]);
            res[i++] = ((((set[0] - set[1]) - set[2]) - set[3]) + set[4]);
            res[i++] = ((((set[0] - set[1]) - set[2]) - set[3]) - set[4]);
            res[i++] = ((((set[0] - set[1]) - set[2]) - set[3]) * set[4]);
            res[i++] = ((((set[0] - set[1]) - set[2]) * set[3]) + set[4]);
            res[i++] = ((((set[0] - set[1]) - set[2]) * set[3]) - set[4]);
            res[i++] = ((((set[0] - set[1]) - set[2]) * set[3]) * set[4]);
            res[i++] = ((((set[0] - set[1]) * set[2]) + set[3]) + set[4]);
            res[i++] = ((((set[0] - set[1]) * set[2]) + set[3]) - set[4]);
            res[i++] = ((((set[0] - set[1]) * set[2]) + set[3]) * set[4]);
            res[i++] = ((((set[0] - set[1]) * set[2]) - set[3]) + set[4]);
            res[i++] = ((((set[0] - set[1]) * set[2]) - set[3]) - set[4]);
            res[i++] = ((((set[0] - set[1]) * set[2]) - set[3]) * set[4]);
            res[i++] = ((((set[0] - set[1]) * set[2]) * set[3]) + set[4]);
            res[i++] = ((((set[0] - set[1]) * set[2]) * set[3]) - set[4]);
            res[i++] = ((((set[0] - set[1]) * set[2]) * set[3]) * set[4]);
            res[i++] = ((((set[0] * set[1]) + set[2]) + set[3]) + set[4]);
            res[i++] = ((((set[0] * set[1]) + set[2]) + set[3]) - set[4]);
            res[i++] = ((((set[0] * set[1]) + set[2]) + set[3]) * set[4]);
            res[i++] = ((((set[0] * set[1]) + set[2]) - set[3]) + set[4]);
            res[i++] = ((((set[0] * set[1]) + set[2]) - set[3]) - set[4]);
            res[i++] = ((((set[0] * set[1]) + set[2]) - set[3]) * set[4]);
            res[i++] = ((((set[0] * set[1]) + set[2]) * set[3]) + set[4]);
            res[i++] = ((((set[0] * set[1]) + set[2]) * set[3]) - set[4]);
            res[i++] = ((((set[0] * set[1]) + set[2]) * set[3]) * set[4]);
            res[i++] = ((((set[0] * set[1]) - set[2]) + set[3]) + set[4]);
            res[i++] = ((((set[0] * set[1]) - set[2]) + set[3]) - set[4]);
            res[i++] = ((((set[0] * set[1]) - set[2]) + set[3]) * set[4]);
            res[i++] = ((((set[0] * set[1]) - set[2]) - set[3]) + set[4]);
            res[i++] = ((((set[0] * set[1]) - set[2]) - set[3]) - set[4]);
            res[i++] = ((((set[0] * set[1]) - set[2]) - set[3]) * set[4]);
            res[i++] = ((((set[0] * set[1]) - set[2]) * set[3]) + set[4]);
            res[i++] = ((((set[0] * set[1]) - set[2]) * set[3]) - set[4]);
            res[i++] = ((((set[0] * set[1]) - set[2]) * set[3]) * set[4]);
            res[i++] = ((((set[0] * set[1]) * set[2]) + set[3]) + set[4]);
            res[i++] = ((((set[0] * set[1]) * set[2]) + set[3]) - set[4]);
            res[i++] = ((((set[0] * set[1]) * set[2]) + set[3]) * set[4]);
            res[i++] = ((((set[0] * set[1]) * set[2]) - set[3]) + set[4]);
            res[i++] = ((((set[0] * set[1]) * set[2]) - set[3]) - set[4]);
            res[i++] = ((((set[0] * set[1]) * set[2]) - set[3]) * set[4]);
            res[i++] = ((((set[0] * set[1]) * set[2]) * set[3]) + set[4]);
            res[i++] = ((((set[0] * set[1]) * set[2]) * set[3]) - set[4]);
            res[i] = ((((set[0] * set[1]) * set[2]) * set[3]) * set[4]);

            for (int i = 0; i < 81; i++)
            {
                if (res[i] == 23)
                {
                    found = true;
                    break;
                }
            }
        } while (next_permutation(set, set + 5) && !found);
        if (found)
        {
            cout << "Possible" << endl;
            continue;
        }
        cout << "Impossible" << endl;
    }

    return 0;
}