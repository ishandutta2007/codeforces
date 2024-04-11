#include<bits/stdc++.h>
#define N 1000005	
using namespace std;
int i,j,k,l,s,n,m;
int A[N],vis[N];
int main() {
	for (i=2;i<=1000000;i++) A[i]=1000001;
	for (i=2;i<=1000000;i++) {
		if (!vis[i]) for (j=2;j*i<=1000000;j++) vis[i*j]=1,A[i*j]=min(A[i*j],i*j-i+1);
	}
	scanf("%d",&n);
	int last=n+1;
	int bb=1;
	int o=0;
	while (bb&&o<2) {
		bb=0;
		o++;
		int pp=n;
		for (j=n;j<last;j++) if (A[j]<pp) pp=A[j],bb=1;
		n=pp;
	}
	printf("%d\n",n);
}