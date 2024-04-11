
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
ll n;
inline void work(){
	n=read();
	if(n&1)n++;
	n=n*2.5;
	if(n<15)n=15;
	printf("%lld\n",n);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}