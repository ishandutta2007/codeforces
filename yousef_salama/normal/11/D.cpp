#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int n, m, a, b, st;
bool g[25][25];
long long dp[25][1 << 19];
long long calc(int i, int cycle){
    long long &ret = dp[i][cycle];
    if(ret != -1)return ret;

    int cnt = 0;
    for(int j = 0; j < n; j++)if(cycle & (1 << j))cnt++;

    ret = 0;
    for(int u = 0; u < n; u++)
        if(g[i][u]){
            if(u == (n - 1)){
                if(cnt > 2)ret++;
            }else{
                if(!(cycle & (1 << u)))ret += calc(u, cycle | (1 << u));
            }
        }
    return ret;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a - 1][b - 1] = g[b - 1][a - 1] = true;
    }
    long long ans = 0;
    for(; n > 0; n--){
        for(int i = 0; i < n; i++)
        for(int cycle = 0; cycle < (1 << n); cycle++)
            dp[i][cycle] = -1;
        ans += calc(n - 1, 1 << (n - 1)) >> 1;
    }
    cout << ans << endl;
    return 0;
}