#include<bits/stdc++.h>
using namespace std;
const int N=17,S=1<<N;
int n,m,l,a[N+1][S]={};
int main()
{	
	scanf("%d%d",&n,&m);
	l=1<<n;
	for(int i=0;i<l;++i)
		scanf("%d",&a[0][i]);
	for(int i=1;i<=n;++i)
		for(int j=0;j<(l>>i);++j)
			a[i][j]=i&1 ? a[i-1][j+j]|a[i-1][j+j+1] : a[i-1][j+j]^a[i-1][j+j+1];
	int p,b;
	while(m--)
	{
		scanf("%d%d",&p,&b);
		a[0][--p]=b;
		for(int i=1,k=p/2;i<=n;++i,k/=2)
			a[i][k]=i&1 ? a[i-1][k+k]|a[i-1][k+k+1] : a[i-1][k+k]^a[i-1][k+k+1];
		printf("%d\n",a[n][0]);
	}
	return 0;
}