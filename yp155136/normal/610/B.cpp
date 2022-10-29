#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[200004];
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		long long int min=1000000040;
		int id=0;
		for (int x=0;n>x;x++) {
			scanf("%d",&a[x]);
			if (a[x]<min) min=a[x],id=x;
		}
		int tmp=0;
		long long int ans=0;
		for (int x=0;n>x;x++) {
			int tid=id+x;
			if (tid>=n) tid%=n;
			if (a[tid] == min) {
				if (tmp>ans) ans=tmp;
				tmp=0;
			}
			else tmp++;
		}
		if (tmp>ans) ans=tmp;
		ans += n*min;
		printf("%I64d\n",ans);
	}
}