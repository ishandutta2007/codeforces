#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long ll;

ll m,n,k,a[20],c[20][20],mask,dp[1237654][20],b[20];

//dp[x][y] --> x()(1)y 
ll ans;

int len(ll mask) {
    int ret=0;
    while (mask>0) {
        if (mask%2==1) ret++;
        mask/=2;
    }
    return ret;
}

ll max(ll a,ll b) {
    if (b>a) return b;
    else return a;
}

int main () {
    //cout << len(3) << ' ' << len(7) << endl;
    memset(dp,0,sizeof(dp));
    scanf("%I64d %I64d %I64d",&n,&m,&k);
    //cout << n << ' ' << m << ' ' << k << "XD\n";
    for (int i=1;n>=i;i++) scanf("%I64d",&a[i]);
    for (int i=0;k>i;i++) {
        ll x,y,pp;
        scanf("%I64d %I64d %I64d",&x,&y,&pp);
        c[x][y] = pp;
    }
    //cout << "Finish reading \n";
    b[1]=1;
    dp[1][1] = a[1];
    for (int i=2;20>i;i++) {
        b[i] = 2*b[i-1];
        dp[b[i]][i] = a[i];
    }
    for (mask=0;b[n+1] > mask;mask++) {
        for (int i=1;n>=i;i++) {
            if (b[i] & mask ) {   // 
                for (int j=1;n>=j;j++) {
                    //cout << "In" << endl;
                    if ((mask & b[j]) == 0) {  // 
                        dp[(mask|b[j])][j] = max( (dp[(mask|b[j])][j]) , (dp[mask][i] + c[i][j] + a[j]) );
                        //cout << (dp[(mask|j)][j])<<"; "<<(dp[mask][i] + c[i][j] + a[j]) << " ; ";
                        //cout << "mask = " << mask << " ; ";
                        //cout << "dp[" << (mask|b[j]) << "][" << j << "]=" << dp[mask|b[j]][j] << endl;
                    }
                    
                }
            }
        }
    }
    //cout << "------------------\n";
    for (mask=0;b[n+1] > mask;mask++) {
        if (len(mask) == m) {
            //cout << "In!!!\n";
            for (int j=1;n>=j;j++) {
                //cout << dp[mask][j] << ' ';
                //cout << "dp[" << mask << "][" << j << "]=" << dp[mask][j] << endl;
                if (dp[mask][j] > ans) ans=dp[mask][j];
            }
        }
    }
    
    printf("%I64d\n",ans);
    return 0;
}