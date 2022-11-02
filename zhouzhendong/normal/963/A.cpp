#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
const int N=100005;
const LL mod=1e9+9;
LL n,a,b,k,x,y;
char s[N];
LL Pow(LL x,LL y){
	if (!y)
		return 1LL;
	LL xx=Pow(x,y/2);
	xx=xx*xx%mod;
	if (y&1LL)
		xx=xx*x%mod;
	return xx;
}
LL Inv(LL x){
	return Pow(x,mod-2);
}
LL calc(char ch){
	return ch=='+'?1:mod-1;
}
int main(){
	n=read(),a=read(),b=read(),k=read();
	scanf("%s",s);
	x=0,y=Pow(Inv(a),k)*Pow(b,k)%mod;
	for (int i=0;i<k;i++)
		x=(x+calc(s[i])*Pow(a,n-i)%mod*Pow(b,i)%mod)%mod;
	LL rd=(n+1)/k;
	y=y==1?rd:((Pow(y,rd)+mod-1)*Inv(y-1)%mod);
	printf("%I64d",x*y%mod);
	return 0;
}