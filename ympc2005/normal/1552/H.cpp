#include <bits/stdc++.h>
using namespace std;

int f[9];

void ask_(int k) {
    if (~f[k]) return;

    printf("? %d\n", 200/(1<<k)*200);

    for (int i = (1<<k); i <= 200; i += (1<<k))
        for (int j = 1; j <= 200; j++)
            printf("%d %d\n", i, j);
    
    fflush(stdout);
    scanf("%d", &f[k]);
}

int main() {
    memset(f, -1, sizeof(f));
    ask_(0), f[8] = 0;
    

    int l = 0, r = 7;

    while (l < r) {
        int mid = (l + r + 1)>>1;
        ask_(mid);

        if (f[0] == (1<<mid)*f[mid]) l = mid;
        else r = mid - 1;
    }

    ask_(l + 1);
    int h = abs(f[l + 1]*(1<<l + 1) - f[0])/(1<<l), w = f[0]/h;
    printf("! %d\n", (h + w - 2)<<1);
    return 0;
}