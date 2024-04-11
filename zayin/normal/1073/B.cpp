#include<bits/stdc++.h>
#define maxn 200050
using namespace std;

int n,a[maxn],pos[maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]),pos[a[i]]=i;
		
	int b,last=0;
	for (int k=1;k<=n;++k)
	{
		scanf("%d",&b);
		if (pos[b]>last)
			printf("%d ",pos[b]-last),last=pos[b];
		else
			printf("0 ");
	}
	return 0;
}