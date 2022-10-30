#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 2e5 + 10;

int n, m, a[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    sort(a + 1, a + n + 1);

    if (a[1] == a[n/2 + 1]) {
        cout<<"Bob"<<'\n';
    } else {
        cout<<"Alice"<<'\n';
    }
}