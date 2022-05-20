
#include <iostream>;
#include <vector>;
#include <string>;

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int pph[500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int cases;
    int cur_case = 0;
    cin >> cases;

    while (cur_case < cases) {
        int households;
        cin >> households;
        int pies;
        cin >> pies;
        int i = 0;
        while (i < households) {
            cin >> pph[i++];
        }

        
        cur_case++;
    }
    return 0;
}