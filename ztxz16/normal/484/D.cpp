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

const int N = 1000005;

int n;
int a[N];
long long ans, f[N];

int main() {
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    long long ans = 0, now1 = -(1LL << 62), now2 = -(1LL << 62);
    for (int i = 0; i <= n; i++) {
        f[i] = max(0LL, max(now1 - a[i], now2 + a[i]));
        now1 = max(f[i] + a[i + 1], now1);
        now2 = max(f[i] - a[i + 1], now2);
    }
    
    cout << f[n] << endl;
    return 0;
}