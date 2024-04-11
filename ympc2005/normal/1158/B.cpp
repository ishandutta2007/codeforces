#include <bits/stdc++.h>
using namespace std;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int n, k, a;
    cin>>n>>k;
    a = (n - k)/2 + 1;

    for (int i = 1; i <= n; i++) {
        if (i%a) {
            cout<<1;
        } else {
            cout<<0;
        }
    }
}