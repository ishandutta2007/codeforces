#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

bool d[100100];
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            d[i] = true;
        }
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (d[i] && d[i+j] && d[i+2*j] && d[i+3*j] && d[i+4*j]) {
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    cout << "no" << endl;
    return 0;
}