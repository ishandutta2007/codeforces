#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, a[N];

ll x, y;

void exgcd_(int a, int b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return;
    }

    exgcd_(b, a%b, y, x);
    y -= x*(a/b);
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    if (n == 1) {
        printf("1 1\n%d\n", -a[1]);
        printf("1 1\n0\n1 1\n0\n");
        exit(0);
    }

    exgcd_(n, n - 1, x, y);

    printf("1 %d\n", n);

    for (int i = 1; i <= n; i++) {
        printf("%lld ", -x*n*a[i]);
    }

    puts("");

    printf("2 %d\n", n);

    for (int i = 2; i <= n; i++) {
        printf("%lld ", -y*(n - 1)*a[i]);
    }

    puts("");

    printf("1 1\n");

    for (int i = 1; i <= 1; i++) {
        printf("%lld ", -y*(n - 1)*a[i]);
    }

    puts("");
}