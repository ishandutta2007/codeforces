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

const int MAX = 10000000;
const int N = 100005;

int no[MAX + 5];
int n, m, a[N], b[N], sa[MAX + 5], sb[MAX + 5];

int main() {
    for (int i = 2; i * i <= MAX; i++) {
        if (no[i]) {
            continue;
        }
        
        no[i] = i;
        for (int j = i * i; j <= MAX; j += i) {
            no[j] = i;
        }
    }
    
    for (int i = 1; i <= MAX; i++) {
        if (!no[i]) {
            no[i] = i;
        }
    }
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        while (x != 1) {
            sa[no[x]]++;
            x /= no[x];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        b[i] = x;
        while (x != 1) {
            sb[no[x]]++;
            x /= no[x];
        }
    }
    
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
        int x = a[i], s = 1;
        while (x != 1) {
            int now = no[x];
            if (sa[now] > sb[now]) {
                sa[now]--;
                s *= now;
            }
            
            x /= now;
        }
        
        printf("%d ", s);
    }
    
    printf("\n");
    for (int i = 1; i <= m; i++) {
        int x = b[i], s = 1;
        while (x != 1) {
            int now = no[x];
            if (sb[now] > sa[now]) {
                sb[now]--;
                s *= now;
            }
            
            x /= now;
        }
        
        printf("%d ", s);
    }
    
    printf("\n");
    return 0;
}