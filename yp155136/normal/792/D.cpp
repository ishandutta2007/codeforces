#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 +6;

LL pow(LL a,LL n) {
	LL ret=1;
	for (int i=0;n>i;i++) ret*=a;
	return a;
}

char s[MAX_N];

int main () {
	LL n,q;
	while (scanf("%I64d %I64d",&n,&q) != EOF) {
		while (q--) {
			LL now;
			scanf("%I64d",&now);
			getchar();
			scanf("%s",s);
			int sz=strlen(s);
			for (int i=0;sz>i;i++) {
//				cout<<"i = "<<i<<endl;
//				cout<<"s[i] = "<<s[i]<<endl;
				if (s[i]=='U') {
					if (now==(n+1)/2) continue;
					LL _pow=1;
					while (now%(_pow*2)==0) _pow*=2;
					LL tmpnow=now+_pow;
					if (tmpnow % (_pow*4)==0) now -= _pow;
					else now+=_pow;
				}
				else if (s[i]=='L') {
					if(now%2==1) continue;
					LL _pow=1;
					while (now%(_pow*2)==0) _pow*=2;
					_pow/=2;
					now -= _pow;
				}
				else if (s[i]=='R'){
					if(now%2==1) continue;
					LL _pow=1;
					while (now%(_pow*2)==0) _pow*=2;
					_pow/=2;
					now += _pow;
				}
//				cout<<"now = "<<now<<endl;
			}
			printf("%I64d\n",now);
		}
	}
}