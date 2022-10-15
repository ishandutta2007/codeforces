#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N],b[N];
ll cnt[N],cnt1[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)cnt[i]=cnt1[i]=0;
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),cnt[a[i]]++,cnt1[b[i]]++;
	ll ans=1ll*n*(n-1)*(n-2)/6;
	for(int i=1;i<=n;i++)ans-=(cnt[a[i]]-1)*(cnt1[b[i]]-1);
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}