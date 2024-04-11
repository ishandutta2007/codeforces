#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uint64_t ull;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e6+7,mod=1e9+7;
struct vec{ll x,y;}a[N],sum[N];
vec operator +(vec a,vec b){return {a.x+b.x,a.y+b.y};}
vec operator -(vec a,vec b){return {a.x-b.x,a.y-b.y};}
vec operator *(vec a,ll b){return {a.x*b,a.y*b};}
ll operator *(vec a,vec b){return a.x*b.x+a.y*b.y;}
ll operator ^(vec a,vec b){return a.x*b.y-a.y*b.x;}
ll cross(vec x,vec y,vec z){return (y-x)^(z-x);}
int n;
ll s[N],s1[N];
ll S;
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].y=read();
	for(int i=1;i<=n;i++)a[i+n]=a[i];
	for(int i=1;i<=n;i++)S+=a[i+1]^a[i];
	for(int i=1;i<=n+n;i++)s[i]=(s[i-1]+(a[i]^a[i-1]))%mod,sum[i]=sum[i-1]+a[i],sum[i].x%=mod,sum[i].y%=mod;
	for(int i=1;i<=n+n;i++)s1[i]=(s1[i-1]+s[i])%mod;
	ll res=0;int j=1,ans=0;
	for(int i=1;i<=n;i++){
		while(j<=n+n && res+cross(a[i],a[j+1],a[j])<=S/2)
			res+=cross(a[i],a[j+1],a[j]),j++;
		if(i<j){
			int k=j-i-1;
			ll tmp=(S%mod*k%mod-2*(s1[j]%mod-s[i]%mod*(j-i)%mod-s1[i]%mod-(a[i+1]^a[i])%mod+(a[i]^(sum[j]-sum[i+1]))%mod)%mod)%mod;
			tmp=(tmp+mod)%mod;
			ans=(ans+tmp)%mod;
		}
		res-=cross(a[j],a[i+1],a[i]);
	}
	printf("%d\n",ans);
	return 0;
}