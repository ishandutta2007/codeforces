#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
ll n,k;
inline void work(){
	n=read(),k=read();
	ll ans=0,num=1;
	while(num<=k && num<n)num<<=1,ans++;
	if(num<n)ans+=(n-num+k-1)/k;
	printf("%lld\n",ans);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
    int test=read();
    while(test--)work();
    return 0;
}