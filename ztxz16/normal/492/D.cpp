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

int n, x, y;
int belong[5000005];

int main() {
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &n, &x, &y);
    int p1 = 1, p2 = 1, tot = 0;
    while (1) {
        if (p1 == x && p2 == y) {
            belong[++tot] = 3;
            belong[++tot] = 3;
            break;
        }
        
        if ((long long)p1 * y < (long long)p2 * x) {
            belong[++tot] = 1;
            p1++;
        } else if ((long long)p1 * y > (long long)p2 * x) {
            belong[++tot] = 2;
            p2++;
        } else {
            belong[++tot] = 3;
            belong[++tot] = 3;
            p1++, p2++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int h;
        scanf("%d", &h);
        h = (h - 1) % (x + y) + 1;
        if (belong[h] == 1) {
            printf("Vanya\n");
        } else if (belong[h] == 2) {
            printf("Vova\n");
        } else {
            printf("Both\n");
        }
    }
    
    return 0;
}