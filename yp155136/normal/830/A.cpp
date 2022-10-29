#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAX_N = 2006;
const LL INF = 1e17 + 6;

LL a[MAX_N];
LL b[MAX_N];
LL mn[MAX_N][MAX_N];
LL dp[MAX_N][MAX_N];

int main () {
    int n,m;
    LL p;
    scanf("%d %d %lld",&n,&m,&p);
    for (int i=1;n>=i;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;m>=i;i++) scanf("%lld",&b[i]);
    sort(b+1,b+m+1);
    for (int i=0;n>=i;i++) {
        for (int j=0;m>=j;j++) {
            mn[i][j] = INF;
        }
    }
    mn[0][0] = INF;
    for (int j=0;m>=j;j++) mn[0][j]=0;
    LL ans=INF;
    for (int i=1;n>=i;i++) {
        LL mnn=dp[i-1][i-1];
        for (int j=i;m>=j;j++) {
            if(i!=1)dp[i][j] = max(abs(a[i]-b[j]) + abs(b[j] - p) , mnn );
            else dp[i][j] = abs(a[i]-b[j]) + abs(b[j]-p);
            mnn = min(mnn,dp[i-1][j]);
            if (i==n) ans = min(ans,dp[i][j]);
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }

    printf("%lld\n",ans);
}