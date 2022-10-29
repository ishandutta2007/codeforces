#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		LL now = 2;
		for (LL i=1;n>=i;i++) {
//			cout<<"now = "<<now<<endl;
			LL to = (i)*(i+1);
			if (i!=1)printf("%I64d\n",i*(i+1)*(i+1)-i+1);
			else puts("2");
			now= i * (i+1) ;
		}
	}
}