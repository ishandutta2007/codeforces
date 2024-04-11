#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ
#define pi 3.1415926535897932384626433
#define eps 1e-9

using namespace std;

int FASTBUFFER;

int n, Number[2000005], full, i, j, Now;
double l, r, dx, dy, xx, yy, ans, x[25], y[25], a[25], ca[25], sa[25], f[2000005];

int main()
{
    scanf("%d %lf %lf", &n, &l, &r);
    Number[1] = 1;
    for (i = 2; i <= 2000000; i++)
        Number[i] = Number[i >> 1] + 1;
    for (i = 1; i <= n; i++)
        scanf("%lf %lf %lf", &x[i], &y[i], &a[i]), a[i] /= 180, a[i] *= pi, ca[i] = cos(a[i]), sa[i] = sin(a[i]);
    f[0] = ans = l;
    full = (1 << n);
    for (i = 1; i < full; i++)
    {
        f[i] = l;
        for (j = i; j > 0; j -= j & (0 - j))
        {
            Now = Number[j & (0 - j)];
            f[i] = max(f[i], f[i - (j & (0 - j))]);
            dx = f[i - (j & (0 - j))] - x[Now];
            dy = -y[Now];
            xx = dx * ca[Now] - dy * sa[Now];
            yy = dx * sa[Now] + dy * ca[Now];
            if (yy > 0 - eps)
            {
                printf("%.10lf\n", r - l);
                return 0;
            }
            
            f[i] = max(f[i], x[Now] + xx * fabs(y[Now] / yy));
        }
        
        ans = max(ans, f[i]);
    }
    
    ans = min(ans, r);
    printf("%.10f\n", ans - l);
    return 0;
}