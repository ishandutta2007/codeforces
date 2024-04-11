#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int T, n;

int main() {
    cin>>T;

    while (T--) {
        cin>>n;
        vector <int> a;
        int mn = 9;

        while (n) {
            a.push_back(n%10);
            mn = min(mn, n%10);
            n /= 10;
        }

        if (a.size() == 2 && a[1] == mn && a[0] != mn) {
            printf("%d\n", a[0]);
        } else {
            printf("%d\n", mn);
        }
    }
}