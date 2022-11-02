#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n;

char s[2][N];

int solve_(int l, int r) {
    if (l > r) return 0;

    int res = 0;

    for (int i = l, j = 0, k = 0; i <= r; i++) 
        if (s[0][i] == '0') {
            res++;

            if (j)
                res++, j = 0;  
            else
                k = 1;
        } else {
            if (k)
                res++, k = 0;
            else
                j++;
        }
    
    return res;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        int ans = 0;
        scanf("%d%s%s", &n, s[0] + 1, s[1] + 1);

        for (int i = 1, j = 0; i <= n + 1; i++)
            if (i == n + 1 || s[0][i] != s[1][i]) {
                ans += solve_(j + 1, i - 1);

                if (i <= n)
                    ans += 2, j = i;
            }
        
        printf("%d\n", ans);
    }
}