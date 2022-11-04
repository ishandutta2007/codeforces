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

const int N = 100005;
int n, l, a[N];

int main() {
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    sort(a + 1, a + n + 1);
    double ans = max((double)a[1], (double)(l - a[n]));
    for (int i = 1; i < n; i++) {
        ans = max(ans, (double)(a[i + 1] - a[i]) * 0.5);
    }
    
    printf("%.12f\n", ans);
    return 0;
}