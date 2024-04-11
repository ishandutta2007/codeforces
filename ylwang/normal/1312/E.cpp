#include<bits/stdc++.h>
using namespace std;

const int MAXN = 510;

int n;
int a[MAXN];
int dp1[MAXN][MAXN],dp2[MAXN]; 

signed main () {
    scanf("%d",&n);
    for(register int i = 1;i <= n; ++i)
        scanf("%d",&a[i]),dp1[i][i] = a[i];
    for(register int l = 2;l <= n; ++l) {//
        for(register int i = 1,j;i + l - 1 <= n; ++i) {
            j = i + l - 1;
            for(register int p = i;p < j; ++p)
                if(dp1[i][p] && dp1[i][p] == dp1[p + 1][j]) dp1[i][j] = dp1[i][p] + 1;  
        }
    }
    for(register int i = 1;i <= n; ++i) {
        dp2[i] = i;
        for(register int j = 1;j <= i; ++j)
            if(dp1[j][i]) dp2[i] = min(dp2[i],dp2[j - 1] + 1);
    }
    cout << dp2[n] << endl;
    return 0;//End.
}