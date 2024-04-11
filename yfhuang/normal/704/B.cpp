//
//  main.cpp
//  D
//
//  Created by  on 8/8/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 5005;

int x[maxn],a[maxn],b[maxn],c[maxn],d[maxn],s,e,n;

long long dp[maxn][maxn];

bool vis[maxn][maxn];

long long solve(int i, int j, int k)
{
    if(i == n)
    {
        if(j == 0 && k == 0) return 0;
        return (long long)(1e18);
    }
    if(j == 0 && k == 0 && i) return (long long)(1e18);
    long long &ret = dp[i][j];
    if(vis[i][j]) return ret;
    vis[i][j] = true;
    ret = (long long)(1e18);
    if(i == s)
    {
        if(j) ret = min(ret, solve(i + 1, j - 1, k) + x[i] + c[i]);
        ret = min(ret, solve(i + 1, j, k + 1) - x[i] + d[i]);
        return ret;
    }
    if(i == e)
    {
        if(k) ret = min(ret, solve(i + 1, j, k - 1) + x[i] + a[i]);
        ret = min(ret, solve(i + 1, j + 1, k) - x[i] + b[i]);
        return ret;
    }
    if(k && j) ret = min(ret, solve(i + 1, j - 1, k - 1) + 2 * x[i] + a[i] + c[i]);
    if(k) ret = min(ret, solve(i + 1, j, k) + a[i] + d[i]);
    if(j) ret = min(ret, solve(i + 1, j, k) + b[i] + c[i]);
    ret = min(ret, solve(i + 1, j + 1, k + 1) - 2 * x[i] + b[i] + d[i]);
    return ret;
}


int main(int argc, const char * argv[]) {
    cin >> n >> s >> e;
    s--;e--;
    for(int i = 0;i < n;i++) scanf("%d",x + i);
    for(int i = 0;i < n;i++) scanf("%d",a + i);
    for(int i = 0;i < n;i++) scanf("%d",b + i);
    for(int i = 0;i < n;i++) scanf("%d",c + i);
    for(int i = 0;i < n;i++) scanf("%d",d + i);
    cout << solve(0,0,0) << endl;
    return 0;
}