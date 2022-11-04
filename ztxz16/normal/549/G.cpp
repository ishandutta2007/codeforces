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

const int N = 200005;

int n, b[N];
pair <int, int> a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
        a[i].first -= (n - i);
    }
    
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = a[i].first + (n - a[i].second);
        b[i] -= (i - a[i].second);
    }
    
    for (int i = 1; i < n; i++) {
        if (b[i] > b[i + 1]) {
            printf(":(\n");
            return 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }
    
    printf("\n");
    return 0;
}