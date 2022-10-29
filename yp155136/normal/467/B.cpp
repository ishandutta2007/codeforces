#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1006;

int a[MAX_N];

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		for (int i=1;m>=i;i++) {
			scanf("%d",&a[i]);
		}
		int x;
		scanf("%d",&x);
		int ans=0;
		for (int i=1;m>=i;i++) {
			int tmp=x;
			int dif=0;
			while (tmp || a[i]) {
				if (tmp%2 != a[i]%2) dif++;
				tmp/=2;
				a[i]/=2;
			}
			if (dif <= k) ans++;
		}
		printf("%d\n",ans);
	}
}