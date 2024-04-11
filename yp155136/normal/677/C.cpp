#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long LL;

const LL mod = 1e9+7;

LL f(LL a) {
	LL ret=0;
	for (int x=0;6>x;x++) {
		if (a%2==0) ret++;
		a/=2;
	}
	return ret;
}

LL fast_pow(LL a,LL n) {
	//not 
	LL ret=1;
	for (int x=0;n>x;x++) {
		ret*=a;
		ret%=mod;
	}
	return ret;
}

int main () {
	string a;
	while (cin >> a) {
		int len=a.size();
		LL ans=0;
		for (int x=0;len>x;x++) {
			int tmp;
			if (a[x]=='-') tmp=62;
			else if (a[x]=='_') tmp=63;
			else if (a[x]<='9') {
				tmp=a[x]-'0';
			}
			else if (a[x]<='Z') {
				tmp=a[x]-'A'+10;
			}
			else if (a[x]<='z'){
				tmp=a[x]-'a'+36;
			}
			ans+=f(tmp);
		}
		printf("%I64d\n",fast_pow(3,ans)%mod);
	}
}