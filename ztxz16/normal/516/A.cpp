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

int n;
int s[16];
char str[105];

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) {
        char ch;
        int x = str[i] - 48;
        for (int j = 1; j <= x; j++) {
            s[j]++;
        }
    }
    
    s[3] += s[9] * 2;
    s[2] += s[8] * 3;
    s[3] += s[6];
    s[2] += s[6];
    s[2] += s[4] * 2;
    for (int i = 1; i <= s[7]; i++) {
        printf("7");
        s[2] -= 4;
        s[3] -= 2;
        s[5] -= 1;
    }
    
    for (int i = 1; i <= s[5]; i++) {
        printf("5");
        s[2] -= 3;
        s[3] -= 1;
    }
    
    for (int i = 1; i <= s[3]; i++) {
        printf("3");
        s[2]--;
    }
    
    for (int i = 1; i <= s[2]; i++) {
        printf("2");
    }
    
    printf("\n");
    return 0;
}