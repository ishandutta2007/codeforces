#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int n,a[100005],x,y,z,flg[200005],pr[200005],cnt=0;
long long ans=1;
multiset<int>st[200005];
multiset<int>::iterator it;
int main()
{
	for(int i=2;i<=200000;i++)
	{
		if(!flg[i])
		{
			flg[i]=i;
			pr[++cnt]=i;
		}
		for(int j=1;j<=cnt&&pr[j]<=flg[i]&&pr[j]*i<=200000;j++)flg[pr[j]*i]=pr[j];
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		while(x>1)
		{
			y=flg[x];z=0;
			while(flg[x]==y)
			{
				x/=flg[x];
				z++;
			}
			st[y].insert(z);
		}
	}
	for(int i=1;i<=200000;i++)
	{
		if(st[i].size()<=n-2)continue;
		if(st[i].size()==n)
		{
			it=st[i].begin();
			it++;
			x=*it;
			for(int j=1;j<=x;j++)ans=ans*i;
		}
		else
		{
			it=st[i].begin();
			x=*it;
			for(int j=1;j<=x;j++)ans=ans*i;
		}
	}
	printf("%lld\n",ans);
	return 0;
}