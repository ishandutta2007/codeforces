#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4 + 10;

char s[N];

int n;

bool chk_(int p) {
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        cnt += s[i] != s[p + i - 1];
    }

    if (!cnt) {
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (s[p + i - 1] != s[p + n - i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);

    int l = 1, r = n;

    while (l <= n && s[l] == s[1]) {
        l++;
    }

    while (r && s[r] == s[1]) {
        r--;
    }

    if (l == r || l > n) {
        puts("Impossible");
        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        s[i + n] = s[i];
    }

    for (int i = 2; i <= n; i++) {
        if (chk_(i)) {
            puts("1");
            exit(0);
        }
    }

    puts("2");
}