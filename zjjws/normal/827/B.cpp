#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=2e5+3;
int a[MAX];
int x[MAX];
int y[MAX];
int n,k;
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main()
{
	int i,j;
	n=rin(),k=rin();
	if(k==n-1)
	{
		printf("2\n");
		for(i=1;i<=k;i++)printf("%d %d\n",i,n);
		return 0;
	}
	if(k==n-2)
	{
		printf("3\n");
		for(i=1;i<k;i++)printf("%d %d\n",i,n);
		printf("%d %d\n%d %d\n",k,k+1,k+1,n); 
		return 0;
	}
	printf("%d\n",(n-k-1-1)/k+1+(n-k-1-1-1)/k+1+2);
	for(i=1;i<=k;i++)a[i]=n;
	for(i=k+1,j=1;i<n;i++)
	{
		printf("%d %d\n",a[j],i);
		a[j]=i;
		j++;if(j==k+1)j=1;
	}
	for(i=1;i<=k;i++)printf("%d %d\n",a[i],i);
	return 0;
}