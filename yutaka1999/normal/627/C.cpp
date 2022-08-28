#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

P pos[SIZE];
ll cost[SIZE],zan[SIZE];

int main()
{
	int d,n,m;
	scanf("%d %d %d",&d,&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,p;
		scanf("%d %d",&x,&p);
		pos[i]=P(x,p);
	}
	pos[m++]=P(d,0);
	sort(pos,pos+m);
	int s=0,e=0;
	ll sum=n;
	ll ret=0;
	for(int i=0;i<m;i++)
	{
		P p=pos[i];
		while(s<e&&sum<p.first)
		{
			ll gt=n-(sum+zan[s]);
			ll nd=p.first-sum;
			if(gt<nd)
			{
				ret+=gt*cost[s];
				sum+=gt;
				s++;
			}
			else
			{
				ret+=nd*cost[s];
				sum+=nd;
			}
		}
		if(sum<p.first)
		{
			puts("-1");
			return 0;
		}
		while(s<e&&cost[e-1]>=p.second) e--;
		cost[e]=p.second,zan[e]=-p.first;
		e++;
		//printf("%lld : %lld\n",sum,ret);
	}
	printf("%lld\n",ret);
	return 0;
}