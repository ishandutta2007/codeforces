#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
#define int ll
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=3005;
int n,K,num[N];
ll ans,f[N];
vector<ll>a[N];
inline void dp(int v,int w){
	for(int i=K;i>=v;i--)f[i]=max(f[i],f[i-v]+w);
}
void fz(int l,int r){
	if(l==r){
		for(int i=0;i<=min(num[l],K);i++)ans=max(ans,f[K-i]+a[l][i]);
		return;
	}
	int mid=(l+r)>>1;vector<ll>tmp;
	for(int i=0;i<=K;i++)tmp.pb(f[i]);
	for(int i=mid+1;i<=r;i++)dp(num[i],a[i][num[i]]);
	fz(l,mid);
	for(int i=0;i<=K;i++)f[i]=tmp[i];
	for(int i=l;i<=mid;i++)dp(num[i],a[i][num[i]]);
	fz(mid+1,r);
	for(int i=0;i<=K;i++)f[i]=tmp[i];
}
signed main(){
	n=read(),K=read();
	for(int i=1;i<=n;i++){
		num[i]=read();a[i].pb(0);
		for(int j=1;j<=num[i];j++)a[i].pb(a[i][j-1]+read());
	}
	return fz(1,n),cout<<ans,0;
}