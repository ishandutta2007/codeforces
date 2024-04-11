#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		int num[n],check[100001];
		memset(check,0,sizeof(check));
		for (int x=0;n>x;x++) scanf("%d",&num[x]);
		int ans[n];
		memset(ans,0,sizeof(ans));
		for (int x=n-1;x>=0;x--) {
			if (x==n-1) {
				ans[x] = 1;
				check[num[x]]++;
			}
			else {
				if (check[num[x]] == 0) {
					check[num[x]]++;
					ans[x]++;
				}
				ans[x] += ans[x+1];
			}
		}
		for (int x=0;m>x;x++) {
			int t;
			scanf("%d",&t);
			printf("%d\n",ans[t-1]);
		}
	}
}