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

const int N = 1005;

int n, m, q, a, b;
int v[N][N], row[N], col[N];
char type[16];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        row[i] = i;
    }
    
    for (int i = 1; i <= m; i++) {
        col[i] = i;
    }
    
    while (q--) {
        scanf("%s", type);
        scanf("%d %d", &a, &b);
        if (type[0] == 'r') {
            swap(row[a], row[b]);
        } else if (type[0] == 'c') {
            swap(col[a], col[b]);
        } else {
            printf("%d\n", v[row[a]][col[b]]);
        }
    }
    
    return 0;
}