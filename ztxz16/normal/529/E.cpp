#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, k;
int a[10005];

map <int, int> ans;

int main() {
  //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        for (int j = 0; j <= k; j++) {
            int x = j * a[i];
            if (ans.find(x) == ans.end()) {
                ans[x] = j;
            } else {
                ans[x] = min(ans[x], j);
            }
        }
    }
    
    int q;
    scanf("%d", &q);
    while (q--) {
        int lastAns = k + 1, y;
        scanf("%d", &y);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                int x = y - j * a[i];
                if (ans.find(x) != ans.end()) {
                    lastAns = min(lastAns, j + ans[x]);
                }
            }
        }
        
        if (lastAns > k) {
            printf("-1\n");
        } else {
            printf("%d\n", lastAns);
        }
    }
    
    return 0;
}