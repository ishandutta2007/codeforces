#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int m;
		scanf("%d",&m);
		int a[n];
		for (int x=0;n>x;x++) scanf("%d",&a[x]);
		sort(a,a+n);
		reverse(a,a+n);
		int ans=0;
		for (int x=0;n>x;x++) {
			ans++;
			m-=a[x];
			if (m<=0) break;
		}
		printf("%d\n",ans);
	}
}