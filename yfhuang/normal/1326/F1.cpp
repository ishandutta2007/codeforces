#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

typedef long long LL;

const int maxn = (1 << 14) + 5;

vector<LL> dp[maxn][15];

int g[15][15];
char str[20];
int n;


void Dp(){
    for(int i = 1;i < (1 << n);i++){
        for(int j = 0;j < n;j++){
            dp[i][j] = vector<LL>(1 << (__builtin_popcount(i) - 1), 0);
        }
    }
    for(int i = 0;i < n;i++){
        dp[(1 << i)][i][0] = 1;
    }
    for(int st = 1;st < (1 << n);st++){
        for(int j = 0;j < n;j++){
            if(st & (1 << j)){
                int sz = __builtin_popcount(st) - 1;
                sz = (1 << sz);
                for(int k = 0;k < sz;k++){
                    for(int i = 0;i < n;i++){
                        if(st & (1 << i))
                            continue;
                        int k1 = k  + g[j][i] * sz;
                        int st1 = st | (1 << i);
                        dp[st1][i][k1] += dp[st][j][k];
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%s", str);
        for(int j = 0;j < n;j++){
            g[i][j] = str[j] - '0';
        }
    }
    Dp();
    for(int i = 0;i < (1 << (n - 1));i++){
        LL ans = 0;
        for(int j = 0;j < n;j++){
            ans += dp[(1 << n) - 1][j][i];
        }
        printf("%lld ", ans);
    }    
    return 0;
}