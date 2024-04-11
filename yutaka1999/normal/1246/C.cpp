#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 1000000007
#define SIZE 2005
using namespace std;
typedef long long int ll;

char mp[SIZE][SIZE];
int right[SIZE][SIZE],down[SIZE][SIZE];
int rs[SIZE][SIZE],ds[SIZE][SIZE];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=m-1;j>=0;j--)
		{
			if(mp[i][j]=='R') cnt++;
			right[i][j]=cnt;
		}
	}
	for(int i=0;i<m;i++)
	{
		int cnt=0;
		for(int j=n-1;j>=0;j--)
		{
			if(mp[j][i]=='R') cnt++;
			down[j][i]=cnt;
		}
	}
	if(n==1&&m==1)
	{
		puts("1");
		return 0;
	}
	rs[0][0]=1;
	rs[1][0]=MOD-1;
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j>0)
			{
				ds[i][j]+=ds[i][j-1];
				if(ds[i][j]>=MOD) ds[i][j]-=MOD;
			}
			if(i>0)
			{
				rs[i][j]+=rs[i-1][j];
				if(rs[i][j]>=MOD) rs[i][j]-=MOD;
			}
			if(j+1<m)
			{
				rs[i][j+1]+=ds[i][j];
				if(rs[i][j+1]>=MOD) rs[i][j+1]-=MOD;
				int to=n-down[i][j];
				rs[to][j+1]-=ds[i][j];
				if(rs[to][j+1]<0) rs[to][j+1]+=MOD;
			}
			else if(down[i][j]==0)
			{
				ret+=ds[i][j];
				if(ret>=MOD) ret-=MOD;
			}
			if(i+1<n)
			{
				ds[i+1][j]+=rs[i][j];
				if(ds[i+1][j]>=MOD) ds[i+1][j]-=MOD;
				int to=m-right[i][j];
				ds[i+1][to]-=rs[i][j];
				if(ds[i+1][to]<0) ds[i+1][to]+=MOD;
			}
			else if(right[i][j]==0)
			{
				ret+=rs[i][j];
				if(ret>=MOD) ret-=MOD;
			}
		}
	}
	printf("%lld\n",ret);
	return 0;
}