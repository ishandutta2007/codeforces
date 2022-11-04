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

const int LIMIT = 1000000;

int n, a[LIMIT + 5], s[LIMIT + 5], now[LIMIT + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[a[i]]++;
    }
    
    for (int i = 1; i <= LIMIT; i++) {
        if (s[i]) {
            now[i] = i;
        } else {
            now[i] = now[i - 1];
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= LIMIT; i++) {
        if (!s[i]) {
            continue;
        }
        
        for (int j = i; j <= LIMIT; j += i) {
            if (now[j - 1] > i) {
                ans = max(ans, now[j - 1] % i);
            }
        }
        
        if (now[LIMIT] > i) {
            ans = max(ans, now[LIMIT] % i);
        }
    }
    
    printf("%d\n", ans);
    return 0;
}