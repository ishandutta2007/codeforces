#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main() {
	LL a,b,c;
	while (scanf("%I64d %I64d %I64d",&a,&b,&c) != EOF) {
		LL mn = min(min(a,b),c);
		a-=mn;
		b-=mn;
		c-=mn;
		if (a==0 && b==0 && c==0) puts("0");
		else if (a==0 && b==0) printf("%I64d\n",(c-1)*2);
		else if (a==0 && c==0) printf("%I64d\n",(b-1)*2);
		else if (b==0 && c==0) printf("%I64d\n",(a-1)*2);
		else if (a==0) {
			if (b>c) printf("%I64d\n",b-1 + (b-1)-c);
			else if (c>b)printf("%I64d\n",c-1 + (c-1)-b);
			else printf("%I64d\n",b-1);
		}
		else if (b==0) {
			if (a>c) printf("%I64d\n",a-1 + (a-1)-c);
			else if (c>a )printf("%I64d\n",c-1 + (c-1)-a);
			else printf("%I64d\n",a-1);
		}
		else if (c==0) {
			if (a>b) printf("%I64d\n",a-1 + (a-1)-b);
			else if (b>a)printf("%I64d\n",b-1 + (b-1)-a);
			else printf("%I64d\n",a-1);
		}
	}
}