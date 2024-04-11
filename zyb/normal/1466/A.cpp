#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define N 500005
int i,j,k,l,s,n,m,f[N][2][2];
int a[N],b[N]; 
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		memset(b,0,sizeof(b));
		scanf("%d",&a[0]);
		for (int i=1;i<=a[0];i++) {
			scanf("%d",&a[i]);
			for (int j=1;j<i;j++) b[a[i]-a[j]]=1;
		}
		int ans=0;
		for (int i=1;i<=50;i++) 
		if (b[i]) ans++;
		printf("%d\n",ans);
	}
}