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

const int N = 100005;

int n, t, a[N], f[N];

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &t);
    f[1] = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (f[i]) {
            f[i + x] = 1;
        }
    }
    
    if (f[t]) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}