#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,x,m,a[N]={},w[N]={},in[N]={},f[N]={};
int main()
{	
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		++in[a[i]];
	}
	for(int i=1;i<=n;++i)
		if(!in[i])
		{
			int t=0,y=i;
			bool flag=y==x;
			while(y)
			{
				y=a[y],++t;
				flag|=y==x;
			}
			if(!flag)
				w[++m]=t;
		}
	int y=x,t=0;
	while(y)
		y=a[y],++t;
	x=t;
	f[0]=true;
	for(int i=1;i<=m;++i)
		for(int j=n;j>=w[i];--j)
			f[j]|=f[j-w[i]];
	for(int i=0;i<=n;++i)
		if(f[i])
			cout<<i+x<<endl;
	return 0;
}