#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#define SIZE 100005
#define BT 20

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

set <P> lr[BT],rl[BT];
set <P>::iterator it;
int in[SIZE];
ll now;

ll get(int x)
{
	return (ll) x*(ll) (x+1)/2;
}
void add(int k)
{
	for(int i=0;i<BT;i++)
	{
		if(in[k]>>i&1)
		{
			int l=k,r=k;
			it=lr[i].lower_bound(P(k+1,-1));
			ll pl=0;
			if(it!=lr[i].end()&&(*it).first==k+1)
			{
				P p=*it;
				lr[i].erase(it);
				rl[i].erase(P(p.second,p.first));
				int len=p.second-p.first+1;
				pl-=get(len);
				r=p.second;
			}
			it=rl[i].lower_bound(P(k-1,-1));
			if(it!=rl[i].end()&&(*it).first==k-1)
			{
				P p=*it;
				rl[i].erase(it);
				lr[i].erase(P(p.second,p.first));
				int len=p.first-p.second+1;
				pl-=get(len);
				l=p.second;
			}
			pl+=get(r-l+1);
			lr[i].insert(P(l,r));
			rl[i].insert(P(r,l));
			now+=(1LL<<i)*pl;
		}
	}
}
void rem(int k)
{
	for(int i=0;i<BT;i++)
	{
		if(in[k]>>i&1)
		{
			it=lr[i].lower_bound(P(k+1,-1));it--;
			int l=(*it).first,r=(*it).second;
			lr[i].erase(it);
			rl[i].erase(P(r,l));
			ll pl=-get(r-l+1);
			if(k+1<=r)
			{
				lr[i].insert(P(k+1,r));
				rl[i].insert(P(r,k+1));
				pl+=get(r-k);
			}
			if(l<=k-1)
			{
				lr[i].insert(P(l,k-1));
				rl[i].insert(P(k-1,l));
				pl+=get(k-l);
			}
			now+=(1LL<<i)*pl;
		}
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		add(i);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;
		rem(a);
		in[a]=b;
		add(a);
		printf("%I64d\n",now);
	}
	return 0;
}