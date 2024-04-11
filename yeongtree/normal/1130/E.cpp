#include <iostream>

using namespace std;

int main()
{
    int k;  cin >> k;
    int a = k % 1999 - 1999;
    int b = (k - a) / 1999 - a;

    cout << "2000\n";
    for(int i = 0; i < 1998; ++i) cout << "0 ";
    cout << a << ' ' << b << endl;

    return 0;
}