#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
typedef long long LL;
const int N = 70;
LL ax, ay, bx, by, ans, n; 
LL x[N], y[N], xs, ys, t;
LL dist(LL x1, LL y1, LL x2, LL y2) { return llabs(x1 - x2) + llabs(y1 - y2); }
int main()
{
    scanf("%lld %lld %lld %lld %lld %lld", x, y, &ax, &ay, &bx, &by);
    scanf("%lld %lld %lld", &xs, &ys, &t);
    while(++n)
    {
        x[n] = ax * x[n - 1] + bx; y[n] = ay * y[n - 1] + by;
        if(x[n] > xs && y[n] > ys && dist(xs, ys, x[n], y[n]) > t) break;
    }
    for(int i = 0; i <= n; i++)
    {
        LL tans = 0, tt = t;
        if(dist(xs, ys, x[i], y[i]) <= tt) tt -= dist(xs, ys, x[i], y[i]), tans++; // S -> Pi 
        else { ans = max(ans, tans); continue; }
        for(int j = i; j; j--) // Pi -> P0
        {
            if(dist(x[j], y[j], x[j - 1], y[j - 1]) <= tt)
                tt -= dist(x[j], y[j], x[j - 1], y[j - 1]), tans++;
            else break;
        }
        for(int j = 1; j <= n; j++) // P0 -> Pi -> P
        {
            if(dist(x[j], y[j], x[j - 1], y[j - 1]) <= tt)
                tt -= dist(x[j], y[j], x[j - 1], y[j - 1]), tans += j > i; //  j > i  
            else break;
        }
        ans = max(ans, tans);
    }
    printf("%lld\n", ans);
    return 0;
}