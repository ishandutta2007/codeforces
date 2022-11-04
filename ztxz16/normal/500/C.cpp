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

const int N = 1005;

int n, m;
int w[N], ord[N], hashNow[N];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d", &ord[i]);
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = i - 1; j >= 0 && ord[j] != ord[i]; j--) {
            if (hashNow[ord[j]] == i) {
                continue;
            } else {
                ans += w[ord[j]];
                hashNow[ord[j]] = i;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}