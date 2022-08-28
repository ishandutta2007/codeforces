#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#define MOD 1000000007
#define SIZE 1024*64

using namespace std;
typedef long long int ll;

int n;
map <ll,ll> mp1[SIZE],mp2[SIZE];
map <ll,ll>::iterator it;
void make(int p,int now,int all,ll S=0,ll E=0)
{
	if(now==all)
	{
		if(p==1) mp1[S][E]++;
		else mp2[S][E]++;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(S>>i&1) continue;
			int nxt=(now+i)%n;
			if(E>>nxt&1) continue;
			make(p,now+1,all,S|1<<i,E|1<<nxt);
		}
	}
}
int ans[]={1,
0,
18,
0,
1800,
0,
670320,
0,
734832000,
0,
890786230,
0,
695720788,
0,
150347555,
0};
int main()
{
	int a;
	scanf("%d",&a);a--;
	printf("%d\n",ans[a]);
	return 0;
	for(int k=1;k<=16;k++)
	{
		n=k;
		for(int i=0;i<SIZE;i++)
		{
			mp1[i].clear();
			mp2[i].clear();
		}
		make(1,0,n/2);
		make(2,n/2,n);
		ll all=(1<<n)-1;
		ll ret=0;
		for(int i=0;i<=all;i++)
		{
			for(it=mp1[i].begin();it!=mp1[i].end();it++)
			{
				ret+=mp1[i][it->first]*mp2[all^i][all^(it->first)];
				ret%=MOD;
			}
		}
		for(int i=1;i<=n;i++) ret*=i,ret%=MOD;
		printf("%I64d\n",ret);
	}
	return 0;
}