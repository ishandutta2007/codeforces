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

const long long MAX = 1000000000000000000LL;
const int mo = 1000000007;

long long n, a, b;
long long mi1[1005], mi2[1005];
int ans;

void dfs(int now, long long s1, long long s2) { 
    if (now == 1) {
        long long c = a - s1, d = b - s2;
        if (n > a) {
            if ((c - d) % (n - a)) {
                return;
            }
            
            long long x = (c - d) / (n - a), y = c - n * x;
            if (x >= 0 && y >= 0) {
                (ans += 1) %= mo;
            }
        } else if (n < a) {
            if ((d - c) % (a - n)) {
                return;
            }
            
            long long x = (d - c) / (a - n), y = c - n * x;
            if (x >= 0 && y >= 0) {
                (ans += 1) %= mo;
            }
        } else {
            if (c != d) {
                return;
            } else {
                long long x = min(c / n, d / a) + 1;
                (ans += (x % mo)) %= mo;
            }
        }
        
        return;
    } else {
        for (long long x = 0; 1; x++) {
            if (s1 + mi1[now] * x > a || s2 + mi2[now] * x > b) {
                return;
            }
            
            dfs(now - 1, s1 + mi1[now] * x, s2 + mi2[now] * x);
        }
    }
}

int tot;

int main() {
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    if (n == a) {
        if (a == b) {
            if (a == 1) {
                printf("inf\n");
            } else {
                printf("2\n");
            }
        } else {
            printf("0\n");
        }
        
        return 0;
    } else {
        mi1[0] = 1, mi2[0] = 1;
        tot = 0;
        for (tot = 1; 1; tot++) {
            if (a / mi1[tot - 1] >= n && b / mi2[tot - 1] >= a) {
                mi1[tot] = mi1[tot - 1] * n;
                mi2[tot] = mi2[tot - 1] * a;
            } else {
                tot--;
                break;
            }
        }
    }
    
    if (tot == 0) {
        if (a == b) {
            printf("1\n");
        } else {
            printf("0\n");
        }
        
        return 0;
    }
    
    dfs(tot, 0, 0);
    printf("%d\n", ans);
    return 0;
}