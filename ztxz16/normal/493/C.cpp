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

const int N = 500005;

int n, m, x, tot;
pair <int, int> a[N];

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[++tot] = make_pair(x, 1);
    }
    
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &x);
        a[++tot] = make_pair(x, 2);
    }
    
    int now = 3 * (n - m), ans = now, ans1 = 3 * n, now1 = 3 * n;
    sort(a + 1, a + tot + 1);
    for (int i = 1; i <= tot; i++) {
        int j;
        for (j = i; j <= tot && a[j].first == a[i].first; j++);
        for (int k = i; k < j; k++) {
            if (a[k].second == 1) {
                now--;
                now1--;
            } else {
                now++;
            }
        }
        
        if (now > ans) {
            ans = now;
            ans1 = now1;
        }
        
        i = j - 1;
    }
    
    printf("%d:%d\n", ans1, ans1 - ans);
    return 0;
}