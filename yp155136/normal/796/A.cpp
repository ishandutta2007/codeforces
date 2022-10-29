#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		m--;
		int a[n];
		bool can[n];
		for (int i=0;n>i;i++) {
			scanf("%d",&a[i]);
			can[i] = !(a[i]==0);
		}
		int ans=142346;
		for (int i=0;n>i;i++) {
			if (can[i]) {
				if (a[i] <= k) {
					ans = min(ans,abs(i-m)*10);
				}
			}
		}
		printf("%d\n",ans);
	}
}