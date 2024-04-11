#include <set>
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

int k1, k2;
int a1[16], a2[16];

set <long long> s;

long long get() {
    long long ret = k1;
    for (int i = 1; i <= k1; i++) {
        (ret *= 11) += a1[i];
    }
    
    for (int i = 1; i <= k2; i++) {
        (ret *= 11) += a2[i];
    }
    
    return ret;
}

int n;

int main() {
  //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    scanf("%d", &k1);
    for (int i = 1; i <= k1; i++) {
        scanf("%d", &a1[i]);
    }
    
    scanf("%d", &k2);
    for (int i = 1; i <= k2; i++) {
        scanf("%d", &a2[i]);
    }
    
    s.insert(get());
    int ans = 0;
    while (1) {
        ans++;
        if (a1[1] > a2[1]) {
            int t1 = a2[1], t2 = a1[1];
            if (k2 == 1) {
                printf("%d 1\n", ans);
                return 0;
            }
            
            for (int i = 1; i < k1; i++) {
                a1[i] = a1[i + 1];
            }
            
            for (int i = 1; i < k2; i++) {
                a2[i] = a2[i + 1];
            }
            
            k2--;
            a1[k1] = t1, a1[++k1] = t2;
        } else {
            int t1 = a2[1], t2 = a1[1];
            if (k1 == 1) {
                printf("%d 2\n", ans);
                return 0;
            }
            
            for (int i = 1; i < k1; i++) {
                a1[i] = a1[i + 1];
            }
            
            for (int i = 1; i < k2; i++) {
                a2[i] = a2[i + 1];
            }
            
            k1--;
            a2[k2] = t2, a2[++k2] = t1;
        }
        
        long long now = get();
        if (s.find(now) != s.end()) {
            printf("-1\n");
            return 0;
        }
        
        s.insert(now);
    }
    
    return 0;
}