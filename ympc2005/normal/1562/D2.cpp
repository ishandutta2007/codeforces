#include <bits/stdc++.h>
using namespace std;
 
const int N = 3e5 + 10;
 
int T, n, q, a[N];
 
char s[N];
 
int calc_(int l, int r) {
    return (l&1 ? 1 : -1)*(a[r] - a[l - 1]);
}
 
int ask_(int l, int r, int x) {
    return calc_(l, x - 1) + ((x - l)&1 ? -1 : 1)*calc_(x + 1, r);
}
 
int solve_(int x, int y) {
    if (a[y] - a[x] == 0)
        return x;
    
    if (a[y - 1] - a[x - 1] == 0)
        return y;
    
    int l = x, r = y;
 
    while (l < r) {
        int mid = (l + r)>>1;
        
        if (!ask_(x, y, mid))
            return mid;
        
        if (1ll*ask_(x, y, l)*ask_(x, y, mid) < 0)
            r = mid;
        else
            l = mid;
    }
}
 
int main() {
    scanf("%d", &T);
 
    while (T--) {
        scanf("%d%d%s", &n, &q, s + 1);
 
        for (int i = 1; i <= n; i++)
            a[i] = a[i - 1] + (s[i] == '+' ? 1 : -1)*(i&1 ? 1 : -1);
        
        for (int l, r, i = 1; i <= q; i++) {
            scanf("%d%d", &l, &r);
 
            if (a[r] - a[l - 1] == 0) {
                puts("0\n");
                continue;
            }
 
            if ((r - l + 1)&1)  
                printf("1\n%d\n", solve_(l, r));
            else
                printf("2\n%d %d\n", l, solve_(l + 1, r));
        }
    }
}