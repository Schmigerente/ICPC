#include <iostream>;
#include <vector>;
#include <string>;

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    cout << "? insert 2 \n";
    cout << "? insert 1 \n";
    cout << "? insert 1 \n";
    cout << "? insert 3 \n";
    cout.flush();

    int response;

    cout << "? remove \n";
    cout.flush();
    cin >> response;

    if(response == 2) {
        cout << "! queue \n";
        cout.flush();
        return 0;
    }

    if(response == 3) {
        cout << "! stack \n";
        cout.flush();
        return 0;
    }

    cout << "? remove \n";
    cout.flush();
    cin >> response;

    if(response == 1) {
        cout << "! pq \n";
        cout.flush();
        return 0;
    }

    cout << "! set \n";
    cout.flush();


    return 0;
}