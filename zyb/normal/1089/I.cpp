#include<bits/stdc++.h>
using namespace std;
const int n=400;
typedef long long ll;
ll F[405],f[405],g[405],dp[405],s[405][405],t[405],T,M,x;
int o;

void add(ll &x,ll y){
    x+=y; if (x>=M) x-=M;
}

void solve(){
    F[0]=1; for (int i=1;i<=n;i++) F[i]=F[i-1]*i%M;
    s[0][0]=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<=n;j++)
        for (int k=1;k+j<=n;k++)
            add(s[i+1][j+k],s[i][j]*F[k]%M);
    }
    dp[1]=1; f[1]=f[2]=1;
    for (int i=3;i<=n;i++){
        for (int j=0;j<=i;j++) t[j]=0;
        t[0]=1;
        for (int j=0;j<i;j++)
        for (int k=1;k+j<=i&&k<i;k++){
            add(t[j+k],t[j]*f[k]%M);
            if (k>=4) add(t[j+k],t[j]*g[k]%M);
        }
        f[i]=t[i];
        g[i]=F[i];
        add(g[i],M-f[i]);
        add(g[i],M-f[i]);
        dp[i]=g[i];
        //if (i==5) cout << s[4][5] << endl;
        for (int j=4;j<i;j++) add(dp[i],M-dp[j]*s[j][i]%M);
    }
    //for (int i=1;i<=10;i++) cout << f[i] << ' ' << g[i] << ' ' << dp[i] << endl;
}

int main(){
    //freopen("i.in","r",stdin);
    cin >> T >> M;
    solve(); dp[1]=1; dp[2]=2;
    while (T--){
        cin >> x;
        cout << dp[x] << endl;
    }
    return 0;
}