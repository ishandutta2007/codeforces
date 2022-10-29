#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N =106;

int a[MAX_N];
int b[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int x=0;n>x;x++) {
			int i;
			scanf("%d",&i);
			a[i]++;
		}
		int m;
		scanf("%d",&m);
		for (int x=0;m>x;x++) {
			int i;
			scanf("%d",&i);
			b[i]++;
		}
		int cnt=0;
		for (int i=1;100>=i;i++) {
			if (a[i]) {
				int tmp=min(a[i],b[i-1]);
				cnt += tmp;
				a[i] -= tmp;
				b[i-1] -= tmp;
				tmp=min(a[i],b[i]);
				cnt += tmp;
				a[i] -= tmp;
				b[i] -= tmp;
				tmp=min(a[i],b[i+1]);
				cnt += tmp;
				a[i] -= tmp;
				b[i+1] -= tmp;
			}
		}
		printf("%d\n",cnt);
	}
}