#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,p[N+N]={},q[N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		p[i]=q[i]=i;
	for(int k=2;k<=n;++k)
	{
		int tmp=p[k-1];
		for(int s=k-1;s<=n-2;s+=k)
		{
			int next=min(k+n-1,s+k),now=tmp;
			q[now]=next;
			tmp=p[next];
			p[next]=now;
		}
		p[k+n-1]=tmp;
		q[tmp]=k+n-1;
	}
	for(int i=n;i<=n+n-1;++i)
		printf("%d ",p[i]);
	printf("\n");
	return 0;
}