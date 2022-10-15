#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int n;
ll a[N],d[N],lg[N],st[N][19];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n==1){puts("1");return;}
	for(int i=1;i<n;i++)st[i][0]=d[i]=llabs(a[i+1]-a[i]);
	--n;
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int j=1;j<=lg[n];j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=gcd(st[i][j-1],st[i+(1<<j-1)][j-1]);
	int ans=0;
	for(int i=1;i<=n;i++){
		ll D=0;int l=i;
		for(int j=lg[n-i+1];~j;j--)
			if(gcd(D,st[l][j])>1 && l+(1<<j)-1<=n)D=gcd(D,st[l][j]),l+=(1<<j);
		ans=max(ans,l-i);
	}
	printf("%d\n",ans+1);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}