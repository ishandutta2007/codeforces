#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
	LL m;
	while (scanf("%I64d",&m) != EOF) {
		LL L=7,R=1e17;
		while (R-L!=1) {
			LL mid=(L+R)>>1;
//			cout<<"mid="<<mid<<endl;
			bool check=false;
			LL cnt=0;
			for (LL d=2;;d++) {
				if (d*d*d>mid) break;
				cnt+= mid/(d*d*d);
				if (cnt>m) break;
			}
			if (cnt>=m) R=mid;
			else L=mid;
		}
		LL cnt=0;
		for (LL d=2;;d++) {
			if (d*d*d>R) break;
			cnt+=R/(d*d*d);
		}
		printf("%I64d\n",(cnt==m?R:-1));
	}
}