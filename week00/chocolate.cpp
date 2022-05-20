#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int w, h;
    cin >> w >> h;
    cout << w*h-1;
}
