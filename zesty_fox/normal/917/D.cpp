#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=210,MOD=1e9+7,INF=0x3f3f3f3f;

int n,m;

ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int flg[N][N];
ll a[N][N],b[N][N];
bool rev;
ll det(ll a[][N],int n){
    rev=0;
    for(int i=1;i<=n;i++){
        if(!a[i][i]){
            for(int j=i+1;j<=n;j++){
                if(a[j][i]){
                    rev^=1,swap(a[i],a[j]);
                    break;
                }
            }
        }
        ll inv=qpow(a[i][i]);
        for(int j=i+1;j<=n;j++){
            ll mul=a[j][i]*inv%MOD;
            for(int k=1;k<=n;k++) a[j][k]=(a[j][k]-mul*a[i][k]%MOD+MOD)%MOD;
        }
    }
    ll res=1;
    for(int i=1;i<=n;i++) (res*=a[i][i])%=MOD;
    return (res%MOD+MOD)%MOD;
}

void Gauss(ll a[][N],int n){
    for(int i=1;i<=n;i++){
        if(!a[i][i]){
            for(int j=i+1;j<=n;j++){
                if(a[j][i]){
                    rev^=1,swap(a[i],a[j]);
                    break;
                }
            }
        }
        ll inv=qpow(a[i][i]);
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            ll mul=a[j][i]*inv%MOD;
            for(int k=1;k<=n+1;k++) a[j][k]=(a[j][k]-mul*a[i][k]%MOD+MOD)%MOD;
        }
    }
}

int main(){
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        flg[x][y]=flg[y][x]=1;
    }
    for(int x=1;x<=n;x++){
        for(int i=1;i<=n;i++) memset(a[i],0,sizeof(ll)*(n+2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(!flg[i][j]) a[i][j]-=1,a[i][i]+=1;
                else a[i][j]-=x,a[i][i]+=x;
            }
        }
        ll res=det(a,n-1);
        for(int i=1,pw=1;i<=n;i++,pw=(ll)pw*x%MOD) b[x][i]=pw;
        b[x][n+1]=res;
    }
    Gauss(b,n+1);
    for(int i=1;i<=n;i++) printf("%lld ",b[i][n+1]*qpow(b[i][i])%MOD);
    puts("");
    return 0;
}