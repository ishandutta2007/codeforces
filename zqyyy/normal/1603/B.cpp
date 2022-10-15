#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
ll lcm(ll x,ll y){return x/__gcd(x,y)*y;}
ll x,y;
inline void work(){
	x=read(),y=read();
	if(y%x==0)printf("%lld\n",x);
	else if(x>y)printf("%lld\n",x+y);
	else if(x==2)puts("2");
	else printf("%lld\n",(y+y/x*x)/2);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;	
}