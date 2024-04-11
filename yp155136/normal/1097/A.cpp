#include <bits/stdc++.h>
using namespace std;

int main () {
    string a;
    cin >> a;
    int n=5;
    while (n--) {
        string b;
        cin >> b;
        if (b[0] == a[0] || b[1] == a[1]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}