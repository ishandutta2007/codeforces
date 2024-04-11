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

const int N = 505;

int n, f[N], ans[N], a[N], pos[N];
char str[N][N];

int find(int i) {
    return f[i] == i ? i : f[i] = find(f[i]);
}

int main() {
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
    }
    
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i][j] == '1') {
                f[find(i)] = find(j);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!ans[j] && f[find(pos[i])] == find(j)) {
                ans[j] = i;
                break;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    
    return 0;
}