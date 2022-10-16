#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while(cin >> n) {
        int diff = n % 7;
        if (diff) {
            if (n % 10 >= diff)
                n -= diff;
            else
                n += 7 - diff;
        }
        cout << n << '\n';
    }
}