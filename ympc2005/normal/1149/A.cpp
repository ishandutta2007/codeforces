#include <bits/stdc++.h>
using namespace std;

int n, a[3];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for (int x, i = 1; i <= n; i++) {
        cin>>x;
        a[x]++;
    }

    if (a[2]) {
        cout<<"2 ";
        a[2]--;
    }

    if (a[1]) {
        cout<<"1 ";
        a[1]--;
    }

    while (a[2]--) {
        cout<<"2 ";
    }

    while (a[1]--) {
        cout<<"1 ";
    }
}