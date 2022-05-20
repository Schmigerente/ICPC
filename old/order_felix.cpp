#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
using ll = long long;
using dl = double;
using graph = vector<vector<int>>;

struct Entry
{
    ll lower_bound = 0, upper_bound = 0, id = 0;
    Entry()
    {
    }

    Entry(ll l, ll u, ll p)
    {
        lower_bound = l;
        upper_bound = u;
        id = p;
    }
};

vector<Entry> in;
//multiset<Entry, cmp> p_set;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n;
    cin >> n;

    vector<Entry> probs = {};

    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        probs.push_back({l, r, i});
    }

    sort(probs.begin(), probs.end(), [](const Entry &m1, const Entry &m2) { return m1.lower_bound < m2.lower_bound; });

    int vindex = 0;

    auto cmp = [](Entry left, Entry right) { return left.upper_bound > right.upper_bound; };
    priority_queue<Entry, vector<Entry>, decltype(cmp)> pq(cmp);

    for (ll i = 0; i < n; i++)
    {
        while (vindex < n && probs[vindex].lower_bound == i + 1)
        {
            pq.push(probs[vindex]);
            vindex++;
        }
        Entry next_elem = pq.top();
        pq.pop();
        cout << next_elem.id + 1 << " ";
    }
    cout << endl;

    return 0;
}