#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2020,M=2020,K=2020;
int n,m,k,up[N][M]={},down[N][M]={};
int q1[M]={},q2[M]={},v1[M]={},v2[M]={},x[K]={},y[K]={};
char ch[N][M]={};
void update(int p)
{
	for(int i=1;i<=n;++i)
		up[i][p]=ch[i][p]=='X' ? 0 : up[i-1][p]+1;
	for(int i=n;i>=1;--i)
		down[i][p]=ch[i][p]=='X' ? 0 : down[i+1][p]+1;
}
void init()
{
	scanf("%d%d%d\n",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%s\n",ch[i]+1);
}
int calc(int mid)
{
	int h1=1,t1=0,h2=1,t2=0,pos=1,ans=0;
	for(int j=1;j<=m;++j)
	{
		while(pos==j || pos-j <= v1[h1]+v2[h2]-1)
		{
			ans=max(ans,pos-j);
			if(pos<=m)
			{
				while(h1<=t1 && up[mid][pos]<=v1[t1])
					--t1;
				++t1,q1[t1]=pos,v1[t1]=up[mid][pos];
				while(h2<=t2 && down[mid][pos]<=v2[t2])
					--t2;
				++t2,q2[t2]=pos,v2[t2]=down[mid][pos];
				++pos;
			}
			else
				break;
		}
		if(q1[h1]==j)
			++h1;
		if(q2[h2]==j)
			++h2;
	}
	return ans;
}
void work()
{
	for(int i=1;i<=k;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		ch[x[i]][y[i]]='X';
	}
	for(int j=1;j<=m;++j)
		update(j);
	int ans[K]={};
	for(int i=1;i<n;++i)
		ans[k]=max(ans[k],calc(i));
	for(int i=k;i>=1;--i)
	{
		ch[x[i]][y[i]]='.';
		update(y[i]);
		ans[i-1]=max(ans[i],calc(x[i]));
	}
	for(int i=1;i<=k;++i)
		printf("%d\n",ans[i]);
}
int main()
{	
	init();
	work(); 
	return 0;
}