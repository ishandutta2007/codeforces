#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
mt19937 rnd(time(0));
const int N=1e6+7;
int n,cnt,c[7007];
ll ans,a[N],d[7007];
inline void work(){
	ll x=a[rnd()%n+1];cnt=0;
	for(ll i=1;i*i<=x;i++)
		if(x%i==0){
			d[++cnt]=i;
			if(i*i!=x)d[++cnt]=x/i;
		}
	sort(d+1,d+cnt+1);
	for(int i=1;i<=cnt;i++)c[i]=0;
	for(int i=1;i<=n;i++)c[lower_bound(d+1,d+cnt+1,__gcd(x,a[i]))-d]++;
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt;j++)
			if(d[j]%d[i]==0)c[i]+=c[j];
	for(int i=1;i<=cnt;i++)if(c[i]>=(n+1)/2)ans=max(ans,d[i]);
}
int main(){
	n=read(),ans=1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int test=1;test<=10;test++)work();
	printf("%lld\n",ans);
	return 0;	
}