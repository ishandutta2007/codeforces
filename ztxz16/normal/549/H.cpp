#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

double a, b, c, d;

int main() {
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double l = 0, r = 1e10;
    for (int i = 1; i <= 200; i++) {
        double mid = (l + r) * 0.5;
        double l1 = min(min((a - mid) * (d - mid), (a - mid) * (d + mid)), min((a + mid) * (d - mid), (a + mid) * (d + mid)));
        double r1 = max(max((a - mid) * (d - mid), (a - mid) * (d + mid)), max((a + mid) * (d - mid), (a + mid) * (d + mid)));
        double l2 = min(min((b - mid) * (c - mid), (b - mid) * (c + mid)), min((b + mid) * (c - mid), (b + mid) * (c + mid)));
        double r2 = max(max((b - mid) * (c - mid), (b - mid) * (c + mid)), max((b + mid) * (c - mid), (b + mid) * (c + mid)));
        if (l1 > r2 || l2 > r1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    printf("%.10f\n", (l + r) * 0.5);
    return 0;
}