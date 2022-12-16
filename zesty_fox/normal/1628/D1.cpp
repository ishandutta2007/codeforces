#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
using ld=long double;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=2010,MOD=1e9+7,INV2=500000004;

int n,m,k;
ll f[N][N];
ld f1[N][N];

void solve(){
    n=rdi(),m=n-rdi(),k=rdi();
    f[1][0]=f1[1][0]=k,f[1][1]=f1[1][0]=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(!j){
                f[i][j]=(f[i-1][j]+k)%MOD;
                f1[i][j]=f1[i-1][j]+k;
                continue;
            }
            if(j==i){
                f[i][j]=f[i-1][j-1];
                f1[i][j]=f1[i-1][j-1];
                continue;
            }
            double k1=f1[i-1][j],k2=f1[i-1][j-1];
            double x=(k2-k1)/2;
            if(x>k){
                f1[i][j]=k1+k;
                f[i][j]=(f[i-1][j]+k)%MOD;
            }
            else{
                f1[i][j]=(k1+k2)/2;
                f[i][j]=(f[i-1][j]+f[i-1][j-1])*INV2%MOD;
            }
        }
    }

    cout<<f[n][m]<<'\n';

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) f[i][j]=f1[i][j]=0;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}