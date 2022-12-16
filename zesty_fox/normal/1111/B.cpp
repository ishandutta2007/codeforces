#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

const int N=100010;
ll n,k,m,a[N],sum[N];
double ans;
int main(){
    n=read(),k=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=0;i<=min(n-1,m);i++){
        ll add=min(m-i,(ll)(n-i)*k);
        ans=max(ans,1.0*(add+sum[n]-sum[i])/(n-i));
    }
    printf("%.8lf\n",ans);
    return 0;
}