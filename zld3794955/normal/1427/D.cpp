#include<bits/stdc++.h>
using namespace std;
const int N=60;
int n,a[N]={},t,b[N]={},c[N]={},tmp[N]={},ans=0;
vector<int> v[N];
void filp()
{
	++ans;
	for(int i=1;i<=t;++i)
		v[ans].push_back(b[i]);
	for(int i=1;i<=t;++i)
		c[i]=c[i-1]+b[i];
	int p=0;
	for(int i=t;i>=1;--i)
		for(int j=c[i-1]+1;j<=c[i];++j)
			tmp[++p]=a[j];
	copy(tmp+1,tmp+n+1,a+1);
	//for(int i=1;i<=n;++i)
	//	printf("%d ",a[i]);
	//printf("\n");
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	bool flag=false;
	for(int i=2;i<=n;++i)
	{
		t=0;
		//int p0=find(a+1,a+n+1,1)-a;
		int p1=find(a+1,a+n+1,1)-a;
		int p2=find(a+1,a+n+1,i)-a;
		if(flag)	// i-1,1,2,...,i-2
		{
			if(p1>p2)	// ...,i,...i-1,[1,i-2],...
			{
				if(p2>1) b[++t]=p2-1;
				b[++t]=p1-p2-1;
				b[++t]=1;
				b[++t]=i-2;
				if(p1+i-3<n) b[++t]=n-(p1+i-3);
				flag=false;
			}
			else // ...,i-1,[1,i-2],...,i,...
			{
				if(p1>2) b[++t]=p1-2;
				b[++t]=1;
				b[++t]=i-2;
				if(p2-(p1+i-3)>0) b[++t]=p2-(p1+i-3);
				if(n-p2>0) b[++t]=n-p2;
				flag=true;
			}
		}
		else	// 1,2,3,...,i-1
		{
			if(p1>p2) // ...,i,...,[1,i-1],...
			{
				if(p2>1) b[++t]=p2-1;
				b[++t]=p1-p2;
				b[++t]=i-1;
				if(p1+i-2<n)	b[++t]=n-(p1+i-2);
				flag=false;
			}
			else // p1<p2 ...,[1,i-1],...,i,...
			{
				if(p1>1) b[++t]=p1-1;
				b[++t]=p2-p1;
				b[++t]=1;
				if(n-p2>0) b[++t]=n-p2;
				flag=true;
			}
		}
		filp();
	}
	if(flag)
	{
		t=2,b[1]=1,b[2]=n-1;
		filp();
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)
	{
		printf("%d",v[i].size());
		for(int j=0;j<v[i].size();++j)
			printf(" %d",v[i][j]);
		printf("\n");
	}
	
}