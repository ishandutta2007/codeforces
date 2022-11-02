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
int n,m,k;
LL s;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
int main(){
	n=read(),m=read(),k=read();
	s=1LL*n*m;
	LL g=gcd(s,k);
	s/=g,k/=g;
	if (k>2)
		return puts("NO"),0;
	if (k==1)
		s*=2;
//	x1y2-x2y1==s
	LL x1=n,y2=(s+x1-1)/n;
	LL x2=x1*y2-s,y1=1;
	if (!(x2<=n&&y2<=m))
		return puts("NO"),0;
	puts("YES");
	puts("0 0");
	printf("%I64d %I64d\n%I64d %I64d",x1,y1,x2,y2);
	return 0;
}