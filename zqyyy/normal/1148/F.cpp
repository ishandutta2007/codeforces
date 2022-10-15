#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=3e5+7;
int n,a[N],h[N];
ll sum,mask[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),mask[i]=read();
		ll x=mask[i];sum+=a[i];
		while(x)x>>=1,h[i]++;h[i]--;
	}
	if(sum<0)for(int i=1;i<=n;i++)a[i]=-a[i];
	ll ans=0;
	for(int j=0;j<62;j++){
		sum=0;
		for(int i=1;i<=n;i++)
			if(h[i]==j)sum+=a[i];
		if(sum<=0)continue;
		ans|=1ll<<j;
		for(int i=1;i<=n;i++)
			if(mask[i]>>j&1)a[i]=-a[i];
	}
	return cout<<ans,0;
}