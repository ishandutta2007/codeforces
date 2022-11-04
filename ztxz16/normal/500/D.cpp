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

const int N = 200005;

int e[N], succ[N], last[N], size[N], id[N], val[N], now[N], n, q, sum;
long double vv[N];

void dfs(int i, int f) {
    size[i] = 1;
    for (int x = last[i]; x; x = succ[x]) {
        if (e[x] == f) {
            continue;
        }
        
        dfs(e[x], i);
        size[i] += size[e[x]];
    }
    
    for (int x = last[i]; x; x = succ[x]) {
        int y = e[x];
        if (y == f) {
            continue;
        }
        
        long double p1 = size[y], p2 = (long double)n - size[y];
        vv[id[x]] = p1 * (p1 - 1.0) * p2 + p2 * (p2 - 1.0) * p1;
    }
}

int main() {
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e[++sum] = b, succ[sum] = last[a], last[a] = sum;
        e[++sum] = a, succ[sum] = last[b], last[b] = sum;
        val[sum] = val[sum - 1] = c;
        id[sum] = id[sum - 1] = i;
        now[i] = c;
    }
    
    dfs(1, 0);
    long double ans = 0.0, ss, nn = (long double)n;
    ss = n * (n - 1.0) * (n - 2.0);
    ss /= 6.0;
    for (int i = 1; i < n; i++) {
        ans += vv[i] * (long double)(now[i]);
    }
    
    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        ans -= vv[a] * (long double)(now[a] - b);
        now[a] = b;
        printf("%.12f\n", (double)(ans / ss));  
    }
    
    return 0;
}