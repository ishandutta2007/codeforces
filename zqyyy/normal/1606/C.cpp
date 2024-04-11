#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=17;
const ll pw[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int n,K,a[N];
inline void work(){
	n=read(),K=read()+1;
	for(int i=1;i<=n;i++)a[i]=read();
	ll ans=0;
	for(int i=1;i<n;i++){
		int num=pw[a[i+1]-a[i]]-1;
		if(num<=K)K-=num,ans+=1ll*num*pw[a[i]];
		else {ans+=1ll*K*pw[a[i]],K=0;break;}
	}
	if(K)ans+=1ll*K*pw[a[n]];
	printf("%lld\n",ans);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
    int test=read();
    while(test--)work();
    return 0;
}