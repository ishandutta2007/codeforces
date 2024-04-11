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

int n, m, s[N];
char str[N][N];
 
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
    }
    
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        int succ = 0, now;
        for (int j = m; j >= 1; j--) {
            succ += s[j];
            if (str[i][j] == 'B') {
                now = -1;
            } else {
                now = 1;
            }
            
            if (now - succ) {
                ans++;
                s[j] += (now - succ);
                succ += (now - succ);
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}