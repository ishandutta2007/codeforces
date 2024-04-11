#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
inline ll f(ll a,ll x){return x==a?LLONG_MAX:a-3*x*x+3*x-1;}
inline int calc(int a,ll x){
    int l=1,r=a-1;
    while(l<=r){
	int mid=(l+r)>>1;
	if(f(a,mid)<=x)r=mid-1;
	else l=mid+1;
    }
    return l;
}
int n,a[N],b[N];
ll K,sum;
inline bool check(ll mid){
    sum=0;
    for(int i=1;i<=n;i++)sum+=b[i]=calc(a[i],mid);
    return sum<K;
}
signed main(){
    n=read(),K=read();
    for(int i=1;i<=n;i++)a[i]=read();
    ll l=-4e18-1,r=4e18+1;
    while(l+1<r){
	ll mid=(l+r)>>1;
	if(check(mid))r=mid;
	else l=mid;
    }
    if(check(l))r=l;check(r),K-=sum;
    for(int i=n;i;i--)if(K && b[i]<a[i] && f(a[i],b[i])==r)b[i]++,K--;
    for(int i=1;i<=n;i++)printf("%d ",b[i]);
    return 0;
}