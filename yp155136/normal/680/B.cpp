#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main () {
	int a,n;
	while (scanf("%d %d",&n,&a) != EOF) {
		int ans=0;
		int num[n+2];
		memset(num,-1,sizeof(num));
		for (int x=1;n>=x;x++) {
			scanf("%d",&num[x]);
		}
		if (num[a]==1) ans++;
		int L=a-1,R=a+1;
		while (1) {
			if (L<0) L=0;
			if (R>n+1) R=n+1;
			if (L==0 && R==n+1) break;
			else if (L==0) {
				if (num[R]==1) ans++;
			}
			else if (R==n+1) {
				if (num[L]==1) ans++;
			}
			else {
				if (num[R] + num[L] == 2) ans+=2;
			}
			L--,R++;
		}
		printf("%d\n",ans);
	}
}