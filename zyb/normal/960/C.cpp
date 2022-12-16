#include<bits/stdc++.h>
#define N 10000005
using namespace std;
long long i,j,k,l,s,n,m,tot;
long long a[N];
int main() {
	scanf("%I64d%I64d",&n,&m);
	long long gt=1;
	for(i=30;i;i--) {
		while (n>=(1<<i)-1) {
			for (j=1;j<=i;j++) a[++tot]=gt;
			gt+=m;
			n-=(1<<i)-1;
		}
	}
	printf("%I64d\n",tot);
	for (i=1;i<=tot;i++) printf("%I64d ",a[i]);
}