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

int n, m, v[1005], ans;
char str[55][55];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);    
    }
    
    v['f'] = 1;
    v['a'] = 2;
    v['c'] = 4;
    v['e'] = 8;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int tag = 0;
            for (int k = 0; k <= 1; k++) {
                for (int l = 0; l <= 1; l++) {
                    char ch = str[i + k][j + l];
                    tag |= v[ch];
                }
            }
            
            ans += (tag == 15);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}