#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 500005

using namespace std;
typedef long long int ll;

int A[SIZE],cnt[SIZE];
vector <int> pr[SIZE];
bool use[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		int now=A[i];
		for(int j=2;j*j<=now;j++)
		{
			if(now%j==0)
			{
 				while(now%j==0) now/=j;
				pr[i].push_back(j);
			}
		}
		if(now>1) pr[i].push_back(now);
	}
	ll ans=0;
	for(int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);x--;
		int sz=pr[x].size();
		int vl=0;
		for(int S=0;S<1<<sz;S++)
		{
			int now=1,c=0;
			for(int j=0;j<sz;j++)
			{
				if(S>>j&1)
				{
					now*=pr[x][j];
					c++;
				}
			}
			if(use[x]) cnt[now]--;
			if(c%2==0) vl+=cnt[now];
			else vl-=cnt[now];
			if(!use[x]) cnt[now]++;
		}
		if(use[x]) ans-=vl;
		else ans+=vl;
		use[x]=!use[x];
		printf("%I64d\n",ans);
	}
	return 0;
}