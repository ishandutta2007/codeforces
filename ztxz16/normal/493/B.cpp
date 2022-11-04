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

const int N = 200005;

int n, last;
int a[N], b[N];
long long s;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (i == n) {
            last = x;
        }
        
        s += x;
        if (x < 0) {
            b[++b[0]] = -x;
        } else {
            a[++a[0]] = x;
        }
    }
    
    int y = max(a[0], b[0]);
    if (s > 0) {
        printf("first\n");
    } else if (s < 0) {
        printf("second\n");
    } else {
        for (int i = 1; i <= y; i++) {
            if (a[i] > b[i]) {
                printf("first\n");
                return 0;
            } else if (a[i] < b[i]) {
                printf("second\n");
                return 0;
            }
        }
        
        if (last > 0) {
            printf("first\n");
        } else {
            printf("second\n");
        }
    }
    return 0;
}