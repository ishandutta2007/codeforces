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

int maxNumber, h, m, s, n, M, T, isTot, tot, l, ans[1000005], in[1000005];
int is[25][66][66];

int main() {
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &n, &M, &T);
    for (int i = 0; i <= 23; i++) {
        for (int j = 0; j <= 59; j++) {
            for (int k = 0; k <= 59; k++) {
                is[i][j][k] = ++isTot;
            }
        }
    }
    
    tot = 0;
    l = 1;
    maxNumber = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d:%d:%d", &h, &m, &s);
        int now = is[h][m][s];
        while (l <= tot && now - in[l] >= T) {
            l++;
        }
        
        if (tot - l + 1 == M) {
            in[tot] = now;
            ans[i] = tot;
        } else {
            in[++tot] = now;
            ans[i] = tot;
        }
        
        maxNumber = max(maxNumber, tot - l + 1);
    }
    
    if (maxNumber < M) {
        printf("No solution\n");
    } else {
        printf("%d\n", tot);
        for (int i = 1; i <= n; i++) {
            printf("%d\n", ans[i]);
        }
    }
    
    return 0;
}