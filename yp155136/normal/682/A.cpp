#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
	LL n,m;
	while (scanf("%I64d %I64d",&n,&m) != EOF) {
		LL ans=0;
		LL tmp1[6];
		LL tmp2[6];
		LL tt = n/5;
		LL ttt=m/5;
		for (int x=1;5>=x;x++) {
			tmp1[x] = tt + (n-5*tt>=x?1:0);
//			cout<<"tmp1["<<x<<"] = "<<tmp1[x]<<endl;
			tmp2[x] = ttt + (m-5*ttt>=x?1:0);
		}
		for (int x=1;5>=x;x++)
		tmp1[0]=tmp1[5];
		tmp2[0]=tmp2[5];
		for (int x=0;5>x;x++) ans+=tmp1[x]*tmp2[5-x];
		printf("%I64d\n",ans);
	}
}