#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=x*10+ch-48,ch=getchar();
	return x;
}
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
LL n,a,b,c;
int main(){
	n=read();
	while (n--){
		a=read(),b=read(),c=read();
		if (a==0){
			puts("Finite");
			continue;
		}
		LL g=gcd(a,b);
		a/=g,b/=g;
		while (1){
			g=gcd(b,c);
			if (g==1)
				break;
			while (b%g==0)
				b/=g;
		}
		puts(b==1?"Finite":"Infinite");
	}
	return 0;
}