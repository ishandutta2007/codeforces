#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[35][35],q;
int main(){
    cin >> n;
    memset(a,-1,sizeof(a));
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++){
        if (i==1&&j==1) {a[i][j]=0;continue;}
        if (i==n&&j==n) {a[i][j]=0;continue;}
        if (i&1) a[i][j]=0; else a[i][j]=1ll<<(i+j-3);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) printf("%lld ",a[i][j]);puts("");
    }
    fflush(stdout);
    int _; cin >> _;
    while (_--){
        cin >> q;
        int x=1,y=1; printf("%d %d\n",x,y);
        for (int i=0;i<n*2-3;i++){
            if (a[x+1][y]==(q&(1ll<<i))) x++; else y++;
            printf("%d %d\n",x,y);
        }
        printf("%d %d\n",n,n); fflush(stdout);
    }
    return 0;
}