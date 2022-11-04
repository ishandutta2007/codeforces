#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

const int N = 200005;

int n, x, a[N], b[N];

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    
    sort(b + 1, b + n + 1);
    int now = n, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] + b[now] >= x) {
            now--, ans++;
        }
    }
    
    printf("%d %d\n", 1, ans);
    return 0;
}