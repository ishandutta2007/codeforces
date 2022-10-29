#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

const long long int mid = 1000000007;

long long dp[3][100002];
long long sum[100002];

int main () {
    long long int t,k;
    while (scanf("%I64d %I64d",&t,&k) != EOF) {
        
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        /*
        0-->R
        1-->W
        2-->sum
        */
        
        dp[1][1]=1;
        if (k!=1)dp[0][1]=0;
        else dp[0][1]=1;
        dp[2][1]=dp[0][1] + dp[1][1];
        sum[1]=dp[2][1];
        for (int x=2;100000>=x;x++) {
            if (x==k) dp[0][x]=1;
            else if (x<k) dp[0][x]=0;
            else {
                dp[0][x] = dp[2][x-k] + mid;
                dp[0][x]%=mid;
            }
            dp[1][x] = dp[2][x-1] + mid;
            dp[1][x]%=mid;
            dp[2][x]=dp[0][x]+dp[1][x] + mid;
            dp[2][x]%=mid;
            
            sum[x] = sum[x-1] + dp[2][x] + mid;
            sum[x] %= mid;
        }
        for (int y=0;t>y;y++) {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%I64d\n",(sum[b]-sum[a-1]+mid)%mid);
        }
    }
}
/*
3 2
1 3
2 3
4 4
*/