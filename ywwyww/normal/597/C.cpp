#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
int n,k;
ll c[12][100010];
void add(int k,int x,ll v)
{
	for(;x<=n;x+=x&-x)
		c[k][x]+=v;
}
ll sum(int k,int x)
{
	ll s=0;
	for(;x;x-=x&-x)
		s+=c[k][x];
	return s;
}
int main()
{
	scanf("%d%d",&n,&k);
	k++;
	int i,j,x;
	ll s,ans=0;
	memset(c,0,sizeof c);
	add(0,1,1);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(j=k;j>=1;j--)
		{
			s=sum(j-1,x);
			if(j==k)
				ans+=s;
			add(j,x,s);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}