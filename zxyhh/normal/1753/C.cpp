#include<bits/stdc++.h>
#define ll long long
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void solve() ;
int main() {
    int T;
    T=rd();
    for(int i=1;i<=T;i++) {
        solve();
    }
    // solve();
}
#define maxn 500005
#define mod 998244353
int a[maxn],n,x;
int cnt[2];
inline int qpow(int x,int k) {
    int ans=1;
    for(;k;k>>=1,x=1ll*x*x%mod) if (k&1) {
        ans=1ll*x*ans%mod;
    }
    return ans;
}
void solve() {
    n=rd();
    cnt[0]=cnt[1]=0;
    for(int i=1;i<=n;i++) {
        a[i]=rd();
        cnt[a[i]]++;
    }
    int A=0,B=0,C=0,D=0;
    for(int i=1;i<=cnt[0];i++) {
        if (a[i]==0) A++;
        else B++;
    }
    C=cnt[0]-A,D=cnt[1]-B;
    int t=1ll*n*(n-1)/2%mod;
    int ans=0;
    // printf("%d %d\n",A,B,C,D);
    for(;A<=cnt[0];A++,B--,C--,D++) {
        ans=(ans+1ll*t*qpow(1ll*B*C%mod,mod-2))%mod;
    }
    printf("%d\n",ans);
}