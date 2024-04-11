#include <bits/stdc++.h>
using namespace std;

const int N = 300006;
int a[N];

void go() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    bool flag = (a[1] < a[n]);
    if (flag) puts("YES");
    else puts("NO");
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}