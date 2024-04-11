#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x*f;
}
LL a,b,x,y;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
int main(){
	a=read(),b=read(),x=read(),y=read();
//	wy = hx
	LL g=gcd(x,y);
	x/=g,y/=g;
//	h = w * y / x
//	w = kx
//	h = ky
	printf("%I64d",min(a/x,b/y));
	return 0;
}