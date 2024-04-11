#include <bits/stdc++.h>
using namespace std;

char s[2000010];
int Cnt;

void Put0(int &a) {
    if (!a) return;
    s[Cnt++] = '0';
    a--;
}

void Put1(int &a, int &b) {
    if (!a && !b) return;
    if (a) {
        s[Cnt++] = '1';
        a--;
    } else {
        s[Cnt++] = '1';
        s[Cnt++] = '1';
        b--;
    }
}

int main() {
    int n, m;
    Cnt = 0;
    scanf("%d%d", &m, &n);
    for (int twos = 0; twos * 2 <= n; twos++) {
        int ones = n - 2 * twos;
        if (abs(ones + twos - m) <= 1) {
            if (ones + twos - m == -1) {
                Put0(m);
            }
            while (ones || twos || m) {
                Put1(ones, twos);
                Put0(m);
            }
            s[Cnt] = 0;
            puts(s);
            return 0;
        }
    }
    puts("-1");
    return 0;
}