#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 250100
using namespace std;

ll n,md,sum,ans,ds[N],vis[N],nxt[N],dp[N][2];
struct Pq
{
    ll size,sum;
    priority_queue<ll>a,b;
    void push(ll u){a.push(u),size++,sum+=u;}
    void del(ll u){b.push(u),size--,sum-=u;}
    void cle(){for(;!a.empty()&&!b.empty()&&a.top()==b.top();a.pop(),b.pop());}
    void pop(){cle(),sum-=a.top(),a.pop(),size--;}
    bool empty(){cle();return a.empty();}
    ll top(){cle();return a.top();}
}pq[N];
vector<P>to[N];
vector<ll>have[N],use,gg;

inline bool cmp(P u,P v){return ds[u.fi]>ds[v.fi];}
inline void del(ll u)
{
    ll i,t,p,q;
    for(i=0;i<to[u].size();i++)
    {
	p=to[u][i].fi,q=to[u][i].se;
	if(ds[p]<=md) break;
	pq[p].push(q);
    }
}

void dfs(ll now,ll last)
{
//    cerr<<' '<<now<<" "<<last<<endl;
    ll i,j,p,q,cnt=ds[now]-md,res=0;
    vis[now]=md;
    for(;pq[now].size>ds[now]-md;pq[now].pop());
    for(i=0;i<to[now].size();i++)
    {
	p=to[now][i].fi;
	if(ds[p]<=md) break;
	if(p==last) continue;
	dfs(p,now);
    }
    use.clear(),gg.clear();
    
    for(i=0;i<to[now].size();i++)
    {
	p=to[now][i].fi,q=to[now][i].se;
	if(ds[p]<=md) break;
	if(p==last) continue;
	ll t=dp[p][1]+q-dp[p][0];
	if(t<0)
	{
	    cnt--;
	    res+=dp[p][0]+t;
	    continue;
	}
	res+=dp[p][0];
	pq[now].push(t);
	use.push_back(t);
    }
    for(;!pq[now].empty()&&pq[now].size>cnt;pq[now].pop()) gg.push_back(pq[now].top());
    dp[now][0]=res+pq[now].sum;
    for(;!pq[now].empty()&&pq[now].size>cnt-1;pq[now].pop()) gg.push_back(pq[now].top());
    dp[now][1]=res+pq[now].sum;
    for(i=0;i<gg.size();i++) pq[now].push(gg[i]);
    for(i=0;i<use.size();i++) pq[now].del(use[i]);
//    cout<<now<<" "<<dp[now][0]<<' '<<dp[now][1]<<" "<<cnt<<endl;
}

int main()
{
    ll i,j,t,p,q,o;
    cin>>n;
    for(i=1;i<n;i++)
    {
	scanf("%lld%lld%lld",&p,&q,&o);
	to[p].push_back(mp(q,o));
	to[q].push_back(mp(p,o));
	ds[p]++,ds[q]++,sum+=o;
    }
    for(i=1;i<=n;i++)
    {
	have[ds[i]].push_back(i);
	sort(to[i].begin(),to[i].end(),cmp);
    }
    for(i=n;i>=1;i--)
    {
	if(have[i+1].size()) nxt[i]=i+1;
	else nxt[i]=nxt[i+1];
    }
    cout<<sum<<" ";
    for(md=1;md<n;md++)
    {
	ans=0;
	for(i=0;i<have[md].size();i++) del(have[md][i]);
//	cerr<<" "<<md<<endl;
	for(i=md+1;i;i=nxt[i])
	{
	    for(j=0;j<have[i].size();j++)
	    {
		t=have[i][j];
		if(vis[t]==md) continue;
		dfs(t,-1);
		ans+=dp[t][0];
	    }
	}
	printf("%lld ",ans);
    }
}