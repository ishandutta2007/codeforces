#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

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

const int N=1010;

int n,a[N][N];
ll sum[N][N];



void solve(){
    ll ans=0;
    n=rdi();
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++) a[i][j]=rdi();
    }
    for(int i=n+1;i<=2*n;i++){
        for(int j=n+1;j<=2*n;j++) ans+=a[i][j];
    }
    ans+=min({a[n][n+1],a[n+1][n],a[1][n+1],a[2*n][n],a[2*n][1],a[1][2*n],a[n+1][1],a[n][2*n]});
    cout<<ans<<'\n';
    //~ for(int i=1;i<=4*n;i++)
        //~ for(int j=1;j<=4*n;j++)
            //~ a[i][j]=a[(i>2*n)?(i-2*n):i][(j>2*n)?(j-2*n):j];
    //~ for(int i=1;i<=4*n;i++)
        //~ for(int j=1;j<=4*n;j++) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}