#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
int main () {
	LL n;
	while (scanf("%I64d",&n) != EOF) {
		string ans="NO";
		for (LL a=0;1000>a;a++) {
			for (LL b=0;10000>b;b++) {
				LL tmp=n-a*1234567-b*123456;
				if (tmp>=0 && tmp%1234==0) ans="YES";
			}
		}
		cout<<ans<<endl;
	}
}