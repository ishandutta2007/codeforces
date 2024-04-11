#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 25
#define INF 2000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int a[SIZE],b[SIZE];
int mn[SIZE];
P vl[SIZE];
int n,m;

int solve(int S)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(S>>i&1) cnt++;
		else cnt--;
		if(cnt<0) return INF;
	}
	cnt=0;
	for(int i=n-1;i>=0;i--)
	{
		mn[i]=++cnt;
	}
	int ans=0,zan=n*m/2;
	int sz=0;
	for(int i=0;i<n;i++)
	{
		if(S>>i&1)
		{
			ans+=a[i]+(m-1)*b[i];
			zan--;
			vl[sz++]=P(a[i]-b[i],i);
		}
		else
		{
			ans+=b[i]*m;
		}
	}
	sort(vl,vl+sz);
	for(int i=0;i<sz;i++)
	{
		int v=vl[i].first,p=vl[i].second;
		bool ok=true;
		for(int j=p;j>=0;j--)
		{
			if(mn[j]<2)
			{
				ok=false;
				break;
			}
		}
		if(ok)
		{
			if(zan>m-1)
			{
				zan-=m-1;
				ans+=v*(m-1);
				for(int j=p;j>=0;j--) mn[j]-=2;
			}
			else
			{
				ans+=v*zan;
				return ans;
			}
		}
		else
		{
			if(zan>m-2)
			{
				zan-=m-2;
				ans+=v*(m-2);
			}
			else
			{
				ans+=v*zan;
				return ans;
			}
		}
	}
	return INF;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	int ret=INF;
	for(int S=0;S<1<<n;S++) ret=min(ret,solve(S));
	printf("%d\n",ret);
	return 0;
}