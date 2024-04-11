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

using namespace std;

int n;
const int maxn = 4e5 + 5;

int a[maxn];
int cnt[maxn];

typedef long long LL;
LL b[25][25];
LL dp[(1 << 20) + 5];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        a[i]--;
    } 
    for(int i = n;i >= 1;i--){
        for(int j = 0;j < 20;j++){
            b[a[i]][j] += cnt[j];
        }
        cnt[a[i]]++;
    }
    for(int i = 0;i < (1 << 20);i++){
        dp[i] = 1e18;
    }     
    dp[0] = 0;
    for(int i = 0;i < (1 << 20);i++){
        for(int j = 0;j < 20;j++){
            if(i & (1 << j))
                continue;
            LL rev = 0;
            for(int k = 0;k < 20;k++){
                if(i & (1 << k)){
                    rev += b[j][k];
                }
            }
            dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + rev);
        }
    }
    cout << dp[(1 << 20) - 1] << endl;
    return 0;
}