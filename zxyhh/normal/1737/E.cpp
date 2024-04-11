#include<bits/stdc++.h>
#define ll long long 
inline ll rd() {
    ll _x=0;int _ch=getchar(),_f=1;
    for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
    if (_ch=='-'){_f=-1;_ch=getchar();}
    for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
    return _f*_x;
}
#define maxn 1000005
#define mod 1000000007
int n;
int f[maxn];
int sum[maxn];
int ans[maxn];
int qpow(int x,int k) {
    int ans=1;
    for(;k;k>>=1,x=1ll*x*x%mod) if (k&1)
        ans=1ll*ans*x%mod;
    return ans;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        n=rd();
        if (n==1) {
            printf("1\n");
            continue;
        }
        f[n]=2;sum[n+1]=0;sum[n]=2;
        for(int i=n-1;i>=1;i--) {
            f[i]=(sum[i+1]-sum[std::min(n+1,i*2)]+mod)%mod;
            sum[i]=(sum[i+1]+f[i])%mod;
        }
        // printf("%d\n",f[2]);
        ans[1]=0;
        for(int i=2;i<=n;i++) {
            int A=qpow(2,(i-1)-(i-1)/2);
            ans[i]=1ll*A*f[i]%mod;
        }
        int N=qpow(qpow(2,n),mod-2);
        for(int i=1;i<=n;i++) {
            printf("%d\n",1ll*ans[i]*N%mod);
        }
    }
}