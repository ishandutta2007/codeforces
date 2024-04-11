#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, d[N];

int main() {
    cin>>n;

    for (int u, v, i = 1; i < n; i++) {
        cin>>u>>v;
        d[u]++;
        d[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] == 2) {
            puts("NO");
            exit(0);
        }
    }

    puts("YES");
}