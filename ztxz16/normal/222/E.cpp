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

const int N = 55;
const int mo = 1000000007;

struct Matrix {
    int n;
    int v[N][N];
    
    void init(int _n) {
        n = _n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                v[i][j] = 0;
            }
        }
    }
    
    friend Matrix operator * (const Matrix &a, const Matrix &b) {
        int n = a.n;
        Matrix c;
        c.init(n);
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    (c.v[i][j] += (long long)a.v[i][k] * b.v[k][j] % mo) %= mo;
                }
            }
        }
        
        return c;
    }
} x, a;

long long n;
int m, k;

int main() {
    scanf("%I64d %d %d", &n, &m, &k);
    x.init(m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            x.v[i][j] = 1;
        }
    }
    
    for (int i = 1; i <= k; i++) {
        char str[5];
        int a, b;
        scanf("%s", str);
        if (str[0] >= 'a' && str[0] <= 'z') {
            a = str[0] - 'a' + 1;
        } else {
            a = str[0] - 'A' + 27;
        }
        
        if (str[1] >= 'a' && str[1] <= 'z') {
            b = str[1] - 'a' + 1;
        } else {
            b = str[1] - 'A' + 27;
        }
        
        x.v[a][b] = 0;
    }
    
    a.init(m);
    for (int i = 1; i <= m; i++) {
        a.v[i][i] = 1;
    }
    
    n--;
    while (n) {
        if (n & 1) {
            a = a * x;
        }
        
        n >>= 1;
        x = x * x;
    }
    
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            (ans += a.v[i][j]) %= mo;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}