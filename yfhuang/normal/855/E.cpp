#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;
int a[100],tot;
long long dp[11][105][1050][2];
int b;
long long dfs(int n,int state,bool limit,bool zero){
    if(n <= 0) return state == 0;
    if(!limit && dp[b][n][state][zero] != -1) return dp[b][n][state][zero];
    int mx = (limit ? a[n] : b - 1);
    long long res = 0;
    for(int i = 0;i <= mx;i++){
        bool zero1 = zero && (i == 0);
        res += dfs(n - 1,zero1 ? 0 : state ^ (1 << i),limit && (i == mx),zero1);
    }
    if(!limit){
        dp[b][n][state][zero] = res;
        //printf("dp[%d][%d][%d][%d] = %lld\n",b,n,state,zero,dp[b][n][state][zero]);
    }
    return res;
}

long long cal(long long n,int b){
    tot = 0;
    while(n > 0){
        a[++tot] = n % b;
        n /= b;
    }
    return dfs(tot,0,1,1);
}

int main(){
    int q;
    cin >> q;
    memset(dp,-1,sizeof(dp));
    for(int i = 1;i <= q;i++){
        long long l,r;
        scanf("%d",&b);
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",cal(r,b) - cal(l - 1,b));
     //   cout << cal(r,b) << " " << cal(l - 1,b) << endl;
    }

    return 0;
}