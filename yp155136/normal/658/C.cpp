#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;

int a[MAX_N];

int main () {
	int n,d,h;
	while (scanf("%d %d %d",&n,&d,&h) != EOF) {
		memset(a,-1,sizeof(a));
		if (d>2*h) {
			puts("-1");
			continue;
		}
		else if (d>n-1) {
			puts("-1");
			continue;
		}
		if (n==2 ) {
			if (d==1 && h==1) puts("1 2");
			else puts("-1");
			continue;
		}
		int i,j;
		for (i=2,j=1;h>=j;j++,i++) {
			a[i] = i-1;
		}
		d-=h;
		if (d==0 && h==1) {
			puts("-1");
			continue;
		}
		if (i<=n && h==1) {
			for (int i=2;n>=i;i++) {
				if (a[i] == -1) printf("1 %d\n",i);
				else printf("%d %d\n",a[i],i);
			}
			continue;
		}
		bool flag=0;
		for (;d>0;d--,i++) {
			if (!flag) a[i] = 1;
			else a[i] = i-1;
			flag=1;
		}
		for (int i=2;n>=i;i++) {
			if (a[i] == -1) printf("2 %d\n",i);
			else printf("%d %d\n",a[i],i);
		}
	}
}