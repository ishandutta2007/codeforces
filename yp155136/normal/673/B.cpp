#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100003;

int g[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		memset(g,-1,sizeof(g));
		bool check=false;
		int imax=-1,jmin=n+1;
		for (int x=0;m>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			if (j<i) {
				int t=i;
				i=j;
				j=t;
			}
			if (g[i]==2) check=true;
			g[i]=1;
			imax=max(i,imax);
			if (g[j]==1) check=true;
			g[j]=2;
			jmin=min(j,jmin);
		}
		if (check || imax>jmin) puts("0");
		else if (m==0){
			printf("%d\n",n-2+1);
			
		}
		else {
			printf("%d\n",jmin-imax);
		}
	}
}