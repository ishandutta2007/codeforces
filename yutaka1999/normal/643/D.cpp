#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

int par[SIZE],deg[SIZE];;
multiset <P> mn,mx;
set <P> st[SIZE];
set <P>::iterator it;
multiset <P>::iterator its;
ll T[SIZE],score[SIZE];//score qa

ll get(int v)
{
	return T[v]/(deg[v]+1);
}
void erase(int v)
{
	ll vl=score[v]+T[v]-(ll) deg[v]*get(v);
	score[par[v]]-=get(v);
	st[par[v]].erase(P(vl,v));
}
void add(int v)
{
	ll vl=score[v]+T[v]-(ll) deg[v]*get(v);
	score[par[v]]+=get(v);
	st[par[v]].insert(P(vl,v));
}
void rem(int v)
{
	if(!st[v].empty())
	{
		it=st[v].begin();
		P p=*it;p.first+=get(v);
		its=mn.lower_bound(p);
		mn.erase(its);
		it=st[v].end();it--;
		p=*it;p.first+=get(v);
		p.first*=-1;
		its=mx.lower_bound(p);
		mx.erase(its);
	}
}
void ins(int v)
{
	if(!st[v].empty())
	{
		it=st[v].begin();
		P p=*it;p.first+=get(v);
		mn.insert(p);
		it=st[v].end();it--;
		p=*it;p.first+=get(v);
		p.first*=-1;
		mx.insert(p);
	}
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&T[i]);
		deg[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&par[i]);
		par[i]--;
		deg[par[i]]++;
	}
	for(int i=0;i<n;i++) score[par[i]]+=get(i);
	for(int i=0;i<n;i++) st[par[i]].insert(P(score[i]+T[i]-(ll) deg[i]*get(i),i));
	//for(int i=0;i<n;i++) printf("%d %lld\n",deg[i],get(i));
	for(int i=0;i<n;i++) ins(i);
	for(int i=0;i<q;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int v,p;
			scanf("%d %d",&v,&p);v--;p--;
			//reset
			rem(par[v]);rem(par[par[v]]);rem(par[par[par[v]]]);
			erase(par[par[v]]);erase(par[v]);
			if(par[par[par[v]]]==v)
			{
				score[v]+=get(par[par[v]]);
				erase(v);
				score[v]-=get(par[par[v]]);
			}
			else erase(v);
			deg[par[v]]--;
			add(par[v]);add(par[par[v]]);
			ins(par[v]);ins(par[par[v]]);ins(par[par[par[v]]]);
			//add
			par[v]=p;
			rem(par[v]);rem(par[par[v]]);rem(par[par[par[v]]]);
			erase(par[par[v]]);erase(par[v]);
			if(par[par[par[v]]]==v)
			{
				score[v]+=get(par[par[v]]);
				add(v);
				score[v]-=get(par[par[v]]);
			}
			else add(v);
			deg[par[v]]++;
			add(par[v]);add(par[par[v]]);
			ins(par[v]);ins(par[par[v]]);ins(par[par[par[v]]]);
		}
		else if(tp==2)
		{
			int v;
			scanf("%d",&v);v--;
			ll vl=score[v]+T[v]-(ll) deg[v]*get(v);
			//printf("%lld %lld\n",score[v],vl);
			vl+=get(par[v]);
			printf("%lld\n",vl);
		}
		else
		{
			its=mn.begin();
			ll a=its->first;
			its=mx.begin();
			ll b=-its->first;
			printf("%lld %lld\n",a,b);
		}
	}
	return 0;
}