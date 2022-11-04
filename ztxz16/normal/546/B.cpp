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

const int N = 5005;

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        int now = -1;
        for (int j = 1; j <= n; j++) {
            if (a[j] && (now == -1 || a[j] < a[now])) {
                now = j;
            }
        }
        
        for (int j = 1; j <= n; j++) {
            if (a[j] == a[now] && j != now) {
                s++;
                a[j]++;
            }
        }
        
        a[now] = 0;
    }
    
    cout << s << endl;
    return 0;
}