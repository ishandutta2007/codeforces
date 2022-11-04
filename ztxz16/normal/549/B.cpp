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

const int N = 105;

char s[N][N];
int ans[N], n, tot, a[N], now[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    while (1) {
        int tag = 0;
        for (int i = 1; i <= n; i++) {
            if (now[i] == a[i]) {
                tag = i;
                break;
            }
        }
        
        if (!tag) {
            break;
        } else {
            ans[++tot] = tag;
            for (int i = 1; i <= n; i++) {
                now[i] += (s[tag][i] - '0');
            }
        }
    }
    
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++) {
        printf("%d ", ans[i]);
    }
    
    printf("\n");
    return 0;
}