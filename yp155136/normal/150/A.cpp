#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main () {
	long long q;
	scanf("%I64d",&q);
	long long tmp = (long long)sqrt(q);
	long long ans=1;
	if (q==1) {
		cout << q << endl << '0' << endl;
		return 0;
	}
	bool check=false;
	bool kk=false;
	for (int i=2;tmp>=i;i++) {
		if (q%i==0 && check==false) {
			ans*=i;
			check=true;
			q/=i;
			tmp=(long long)sqrt(q);
			i--;
			//break;
			continue;
		}
		else if (q%i==0 && check==true) {
			ans*=i;
			q/=i;
			kk=true;
			break;
		}
	}
	if (kk==true) {
		printf("1\n%I64d\n",ans);
	}
	else if (check==false) puts("1\n0");
	else puts("2");
}