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

long long FASTBUFFER;

using namespace std;

const long long N = 1000005;

long long n, r, avg, tot;
long long a[N], b[N];
pair <long long, long long> v[N];

int main() {
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%I64d %I64d %I64d", &n, &r, &avg);
    long long need = avg * n;
    for (long long i = 1; i <= n; i++) {
        scanf("%I64d %I64d", &a[i], &b[i]);
        need -= a[i];
        v[++tot] = make_pair(b[i], r - a[i]);
    }
    
    sort(v + 1, v + tot + 1);
    long long ans = 0;
    for (long long i = 1; i <= tot; i++) {
        if (need > 0) {
            long long x = min(need, v[i].second);
            ans += x * v[i].first;
            need -= x;
        }
    }
    
    cout << ans << endl;
    return 0;
}