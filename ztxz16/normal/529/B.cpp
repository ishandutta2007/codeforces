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

int n, a[1005], b[1005], c[1005];

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    
    long long ans = (1LL << 62);
    for (int i = 1; i <= 1000; i++) {
        int tag = 0, s = 0, s2 = 0, tot = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] > b[j]) {
                if (b[j] > i) {
                    tag = 1;
                } else {
                    if (a[j] > i) {
                        s += a[j];
                    } else {
                        s += a[j];
                        c[++tot] = a[j] - b[j];
                    }
                }
            } else {
                if (a[j] > i) {
                    tag = 1;
                } else {
                    if (b[j] > i) {
                        s += b[j];
                        s2++;
                    } else {
                        s += a[j];
                    }
                }
            }
        }
        
        if (!tag && s2 <= n / 2) {
            sort(c + 1, c + tot + 1);
            reverse(c + 1, c + tot + 1);
            for (int x = 1; x <= min(tot, n / 2 - s2); x++) {
                s -= c[x];
            }
            
            ans = min(ans, (long long)s * i);
        }
    }
    
    printf("%I64d\n", ans);
    return 0;
}