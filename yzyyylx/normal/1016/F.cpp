#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 300100
using namespace std;

ll n,m,first[N],bb,d[2][N],num[N],sta[N],top,sum;
bool nw;
struct Bn
{
	ll to,next,quan;
}bn[N<<1];
map<P,bool>mm;
priority_queue<P>pq;

inline void add(ll u,ll v,ll w)
{
	bb++;
//	cout<<"   "<<u<<" "<<v<<endl;
	mm[mp(u,v)]=1;
	bn[bb].to=v;
	bn[bb].quan=w;
	bn[bb].next=first[u];
	first[u]=bb;
}

void dfs(ll now,ll last)
{
	ll p,q;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		d[nw][bn[p].to]=d[nw][now]+bn[p].quan;
		dfs(bn[p].to,now);
	}
}

inline bool cmp(ll u,ll v)
{
	return d[0][u]>d[0][v];
}

int main()
{
	memset(first,-1,sizeof(first));
	ll i,j,p,q,o;
	cin>>n>>m;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld%lld",&p,&q,&o);
		add(p,q,o),add(q,p,o);
	}
	dfs(1,-1);
	nw=1;
	dfs(n,-1);
	for(i=1;i<=n;i++) num[i]=i;
	sort(num+1,num+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		for(;!pq.empty();)
		{
			p=pq.top().fi;
			q=pq.top().se;
			if(mm[mp(q,num[i])] || q==num[i])
			{
				sta[++top]=q;
				pq.pop();
				continue;
			}
//			cout<<q<<" "<<num[i]<<endl;
			sum=max(sum,d[0][num[i]]+p);
			break;
		}
		for(;top;top--) pq.push(mp(d[1][sta[top]],sta[top]));
		pq.push(mp(d[1][num[i]],num[i]));
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&o);
		printf("%lld\n",min(o+sum,d[0][n]));
	}
}