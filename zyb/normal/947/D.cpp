#include<bits/stdc++.h>
#define N 1000005
using namespace std;
char c[N],c1[N];
int i,j,k,l,s,n,m,x,y,X,Y,a[N],b[N],A[N],B[N];
int main() {
	scanf("%s",c+1);
	scanf("%s",c1+1);
	n=strlen(c+1);
	for (i=1;i<=n;i++) {
		a[i]=a[i-1]+(c[i]!='A');
		if (c[i]=='A') b[i]=b[i-1]+1;
		else b[i]=0;
	}
	n=strlen(c1+1);
	for (i=1;i<=n;i++) {
		A[i]=A[i-1]+(c1[i]!='A');
		if (c1[i]=='A') B[i]=B[i-1]+1;
		else B[i]=0;
	}
	scanf("%d",&m);
	for (i=1;i<=m;i++) {
		scanf("%d%d%d%d",&x,&y,&X,&Y);
		if (a[y]-a[x-1]>A[Y]-A[X-1]) {
			printf("0"); continue;
		}
		int jb=a[y]-a[x-1],jsb=A[Y]-A[X-1];
		if ((jsb-jb)&1) {
			printf("0"); continue;
		}
		int oo=jsb-jb;
		oo/=2;
		int gt=min(b[y],y-x+1);
		if (gt==y-x+1&&jb<jsb) gt--;
		int gtw=min(B[Y],Y-X+1);
		if (gt<gtw) {
			printf("0"); continue;
		}
		if (!oo&&(gt%3)!=(gtw%3)) {
			printf("0"); continue;
		}
		printf("1");
	}
	puts("");
}