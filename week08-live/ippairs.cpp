#include <bits/stdc++.h>

#define endl "\n"
#define all(e) (e).begin(), (e).end()
#define it(l, u) for (ll i = l; i < u; i++)
#define rev(l, u) for (ll i = u - 1; i >= u; i--)

using namespace std;
using ll = long long;
using dl = double;
using graph = map<ll, vector<ll>>;


struct Node {
    Node* ln;
    // is 1
    Node* rn;
    Node* pn;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content

    ll b, f, q;
    cin >> b >> f >> q;

    Node* start = new Node {NULL, NULL, NULL};

    it (0, f) {
        char c;
        Node* ptr = start;

        for (ll j = 0; j < b; j++) {
            cin >> c;
            if (c == '1') {
                // digit is 1
                if (ptr->rn == NULL) {
                    ptr->rn = new Node {NULL, NULL, ptr};
                }
                ptr = ptr->rn;
            } else {
                // digit is 0
                if (ptr->ln == NULL) {
                    ptr->ln = new Node {NULL, NULL, ptr};
                }
                ptr = ptr->ln;
            }
        }
    }

    it(0 , q) {
        char c;
        Node* ptr = start;

        for (ll j = 0; j < b; j++) {
            cin >> c;
            if (c == '1') {
                // digit is 1
                // to maximize xor take a 0 if possible
                if (ptr->ln == NULL) {
                    // cant maximize go right
                    cout << 1;
                    ptr = ptr->rn;
                } else {
                    // can maximize go left;
                    cout << 0;
                    ptr = ptr->ln;
                }
            } else {
                // digit is 0
                if (ptr->rn == NULL) {
                    cout << 0;
                    ptr = ptr->ln;
                } else {
                    cout << 1;
                    ptr = ptr->rn;
                }
            }
        }
        cout << endl;

        // remove now invalid ip from tree

        while (ptr->pn != NULL) {
            if (ptr->pn->ln == ptr) {
                // node was left
                ptr = ptr->pn;
                delete ptr->ln;
                ptr->ln = NULL;
                if (ptr->rn != NULL) {
                    // done with cleaning up there is now a valid path
                    break;
                }
            } else {
                // node was right
                ptr = ptr->pn;
                delete ptr->rn;
                ptr->rn = NULL;
                if (ptr->ln != NULL) {
                    // done with cleaning there now is a valid path
                    break;
                }
            }
        }
    }


    return 0;
}
