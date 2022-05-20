//rewrite cin for faster performance

#include <iostream>
#include <string>
using namespace std;

int cases;
string arr[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int i = 0 ;

    while (!cin.eof()) {
        cin >> arr[i++];
    }

    cases = stoi(arr[0]);
    int index = 1;

    for (int i = 0; i < cases; i++) {
        int length, querries;
        length = stoi(arr[index++]);
        querries = stoi(arr[index++]);
        index++;
        for (int j = 0; j < querries; j++) {
            switch (stoi(arr[index++])) {
            case 1: 
                if (length == 0) {
                    cout << "yes\n";
                } else {
                    cout << "no\n";
                }
                break;
            case 2:
                cout << length << "\n";
                break;
            case 3:
                index++;
                length--;
                break;
            case 4:
                length++;
            default:
                index += 2;
                break;
            }
        }
    }
}
