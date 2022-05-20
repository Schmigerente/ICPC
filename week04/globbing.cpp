#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for (ll i = l; i < u; i++)
#define rev(l, u) for (ll i = u - 1; i >= u; i--)

using namespace std;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    ll cases;
    cin >> cases;
    string trash;
    getline(cin, trash);
    it(0, cases)
    {
        bool flag = false;
        string pattern, input;
        getline(cin, pattern);
        getline(cin, input);
        ll j = 0;
        ll k;
        while (pattern[j] != '+' && pattern[j] != '*' && j < pattern.length() && j < input.length())
        {
            if (!(pattern[j] == input[j]))
            {
                flag = true;
                break;
            }
            j++;
        }
        if (!flag)
        {
            k = pattern.length() - 1;
            j = input.length() - 1;
            while (pattern[k] != '+' && pattern[k] != '*' && j >= 0 && k >= 0)
            {
                if (!(pattern[k] == input[j]))
                {
                    flag = true;
                    break;
                }
                j--;
                k--;
            }
        }
        cout << (flag || (pattern[k] == '+' || pattern[k] == '*' ? (input.length() < pattern.length() - (pattern[k] == '*' ? 1 : 0)) : pattern.length() != input.length()) ? "No" : "Yes") << endl;
    }

    return 0;
}