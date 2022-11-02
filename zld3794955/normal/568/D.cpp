#include<bits/stdc++.h>
using namespace std;
const int N=100010,K=10;
int n,k,a[N]={},b[N]={},c[N]={};
int rest[N]={};
long long dx=0,dy=0,d=0;
bool intersect(int p,int q)
{
	d=(long long)a[p]*b[q]-(long long)a[q]*b[p];
	if(d==0)
		return false;
	dx=(long long)b[q]*c[p]-(long long)b[p]*c[q];
	dy=(long long)a[p]*c[q]-(long long)a[q]*c[p];
	return true;
}
bool in(int p)
{
	return !(a[p]*dx+b[p]*dy-c[p]*d);
}
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<=n;++i)
		c[i]=-c[i];
}
void work()
{
	for(int T=1;T<=600;++T)
	{
		int pos=n,ans1[K]={},ans2[K]={};
		for(int i=1;i<=pos;++i)
			rest[i]=i;
		for(int i=1;i<=k;++i)
		{
			if(pos<=1)
			{
				ans2[i]=-1,ans1[i]=max(rest[pos],1),pos=0;
				continue;
			}
			int u=rand()%pos+1,v=rand()%pos+1,tot=0;
			if(u==v)
			{
				ans2[i]=-1,ans1[i]=rest[u];
				for(int j=1;j<=pos;++j)
					if(rest[j]!=rest[u])
						rest[++tot]=j;
				pos=tot;
				continue;
			}
			if(!intersect(rest[u],rest[v]))
				break;
			ans1[i]=rest[u],ans2[i]=rest[v];
			//cout<<"dx="<<dx<<" dy="<<dy<<" d="<<d<<endl;
			for(int j=1;j<=pos;++j)
				if(!in(rest[j]))
					rest[++tot]=rest[j];
			pos=tot;
		}
		if(pos)
			continue;
		puts("YES");
		printf("%d\n",k);
		for(int i=1;i<=k;++i)
			printf("%d %d\n",ans1[i],ans2[i]);
		return;
	}
	puts("NO");
}
int main()
{	
	srand(time(0));
	init();
	work();
	return 0;
}