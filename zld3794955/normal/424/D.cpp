#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=330,M=330;
int n,m,t,h[N][M]={},t1,t2,t3,s1[N][M]={},s2[N][M]={},a1[N]={},a2[N]={};
int bx1,bx2,by1,by2,ans=-1000000000;
inline int abs(int x)
{
	return x>=0 ? x : -x;
}
void init()
{
	scanf("%d%d%d",&n,&m,&t);
	scanf("%d%d%d",&t1,&t2,&t3);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&h[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=2;j<=m;++j)
		{
			if(h[i][j]>h[i][j-1])
			{
				s1[i][j]=s1[i][j-1]+t2;
				s2[i][j]=s2[i][j-1]+t3;
			}
			if(h[i][j]<h[i][j-1])
			{
				s1[i][j]=s1[i][j-1]+t3;
				s2[i][j]=s2[i][j-1]+t2;
			}
			if(h[i][j]==h[i][j-1])
			{
				s1[i][j]=s1[i][j-1]+t1;
				s2[i][j]=s2[i][j-1]+t1;
			}
		}
}
void work()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(h[i+1][j]==h[i][j])
				a1[j]=a2[j]=t1;
			if(h[i+1][j]>h[i][j])
			{
				a1[j]=t3;
				a2[j]=t2;
			}
			if(h[i+1][j]<h[i][j])
			{
				a1[j]=t2;
				a2[j]=t3;
			}
		}
		for(int k=i+2;k<=n;++k)
		{
			for(int j=1;j<=m;++j)
			{
				if(h[k][j]==h[k-1][j])
				{
					a1[j]+=t1;
					a2[j]+=t1;
				}
				if(h[k][j]>h[k-1][j])
				{
					a1[j]+=t3;
					a2[j]+=t2;
				}
				if(h[k][j]<h[k-1][j])
				{
					a1[j]+=t2;
					a2[j]+=t3;
				}
			}
			map<int,int>d;
			d[s1[i][1]+s2[k][1]-a1[1]]=1;
			for(int q=3;q<=m;++q)
			{
				int v=s1[i][q]+s2[k][q]+a2[q],f=v-t;
				map<int,int>::iterator it=d.upper_bound(f);
				if(it!=d.end())
				{
					if(abs(v-it->first-t)<abs(ans-t))
					{
						ans=v-it->first;
						bx1=i;
						bx2=k;
						by1=it->second;
						by2=q;
					}
				}
				if(it!=d.begin())
				{
					--it;
					if(abs(v-it->first-t)<abs(ans-t))
					{
						ans=v-it->first;
						bx1=i;
						bx2=k;
						by1=it->second;
						by2=q;
					}
				}
				d[s1[i][q-1]+s2[k][q-1]-a1[q-1]]=q-1;
			}
		}
	}
	printf("%d %d %d %d\n",bx1,by1,bx2,by2);
}
int main()
{	
	init();
	work();
	return 0;
}