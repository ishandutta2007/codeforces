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

const int N = 5000000;

long long s[N + 5];

char isNot[N + 5];
int a, b, test;

void work() {
    scanf("%d %d", &a, &b);
    printf("%I64d\n", s[a] - s[b]);
}

int main() {
    for (int i = 2; i <= N; i++) {
        if (isNot[i]) {
            continue;
        }
        
        for (int j = i; j <= N; j += i) {
            s[j]++;
            isNot[j] = 1;
        }
        
        int k = i;
        while ((long long)k * i <= N) {
            k *= i;
            for (int j = k; j <= N; j += k) {
                s[j]++;
            }
        }
    }
    
    for (int i = 2; i <= N; i++) {
        s[i] += s[i - 1];
    }
    
    scanf("%d", &test);
    while (test--) {
        work();
    }
    
    return 0;
}