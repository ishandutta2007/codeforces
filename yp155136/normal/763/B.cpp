#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		puts("YES");
		for (int i=1;n>=i;i++) {
			LL a,b,c,d;
			cin >> a>>b>>c>>d;
			LL tmp=10000000;
			tmp*=tmp;
			a+=tmp;
			b+=tmp;
			LL ans=(a%2)*2+(b%2)+1;
			cout<<ans<<endl;
		}
	}
}