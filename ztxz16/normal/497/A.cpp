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

const int N = 1005;

int n, m, now[N], temp[N];
char str[N][N];

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
    }
    
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int flag = 0;
        for (int j = 2; j <= n; j++) {
            if (now[j] == now[j - 1] && str[j][i] < str[j - 1][i]) {
                flag = 1;
                break;
            }
        }
        
        if (flag) {
            ans++;
        } else {
            for (int j = 2; j <= n; j++) {
                temp[j] = now[j];
            }
            
            for (int j = 2; j <= n; j++) {
                if (temp[j] != temp[j - 1] || str[j][i] != str[j - 1][i]) {
                    now[j] = now[j - 1] + 1;
                } else {
                    now[j] = now[j - 1];
                }
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}