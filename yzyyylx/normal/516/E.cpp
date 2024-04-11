#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 800100
using namespace std;

ll n,m,x,y,g,ans,tt,bb,dd,st,first[N],dn[N],len[N],d[N];
bool in[N],ok[N];
struct Bn
{
    ll to,next,quan;
}bn[N<<1];
queue<ll>que;
vector<ll>a[N],b[N];
unordered_map<ll,ll>mm[2],use;

ll eg(ll u,ll v,ll &x,ll &y)
{
    if(!v)
    {
	x=1,y=0;
	return u;
    }
    ll res=eg(v,u%v,x,y);
    x=x-u/v*y,swap(x,y);
    return res;
}

inline void add(ll u,ll v,ll w)
{
//    cerr<<"   "<<u<<" "<<v<<" "<<w<<endl;
    bb++;
    bn[bb].to=v;
    bn[bb].next=first[u];
    bn[bb].quan=w;
    first[u]=bb;
}

inline ll disa(ll u,ll v){return y*(((v-u)%n+n)%n/g)%(n/g)*m;}
inline ll disb(ll u,ll v){return x*(((v-u)%m+m)%m/g)%(m/g)*n;}
inline bool cmpa(ll u,ll v){return disa(st,u)<disa(st,v);}
inline bool cmpb(ll u,ll v){return disb(st,u)<disb(st,v);}
inline ll zh(bool u,ll v){if(mm[u].count(v)) return mm[u][v];len[++tt]=v;return mm[u][v]=tt;}

inline ll calc(ll u)
{
    sort(a[u].begin(),a[u].end()),sort(b[u].begin(),b[u].end());
    tt=1,bb=0,mm[0].clear(),mm[1].clear();
    ll i,j,p,q,t,res=0;
//    for(i=1;i<=n;i++) for(j=1;j<=n;j++) cerr<<i<<" "<<j<<" "<<disa(i,j)<<endl;puts("");
//    for(i=1;i<=m;i++) for(j=1;j<=m;j++) cerr<<i<<" "<<j<<" "<<disb(i,j)<<endl;puts("");
    dd=0,use.clear();
    for(i=0;i<a[u].size();i++) dn[++dd]=a[u][i],add(zh(0,a[u][i]),zh(1,a[u][i]%m),0),use[a[u][i]]=1,ok[zh(0,a[u][i])]=1;
    for(i=0;i<b[u].size();i++) if(!use.count(b[u][i]%n)) dn[++dd]=b[u][i],use[b[u][i]%n]=1;
    st=dn[1],sort(dn+1,dn+dd+1,cmpa);
//    cerr<<" "<<dd<<endl;for(i=1;i<=dd;i++) cout<<dn[i]<<" ";puts("");
    for(i=1;i<=dd;i++)
    {
	p=zh(0,dn[i]%n),q=zh(0,dn[i%dd+1]%n);
	add(1,p,dn[i]);
	add(p,q,disa(dn[i]%n,dn[i%dd+1]%n));
	q=zh(0,((dn[i%dd+1]-m)%n+n)%n);
	if(p!=q) add(p,q,disa(dn[i],((dn[i%dd+1]-m)%n+n)%n));
    }

    dd=0,use.clear();
    for(i=0;i<b[u].size();i++) dn[++dd]=b[u][i],add(zh(1,b[u][i]),zh(0,b[u][i]%n),0),use[b[u][i]]=1,ok[zh(1,b[u][i])]=1;
    for(i=0;i<a[u].size();i++) if(!use.count(a[u][i]%m)) dn[++dd]=a[u][i],use[a[u][i]%m]=1;
    st=dn[1],sort(dn+1,dn+dd+1,cmpb);
//    cerr<<" "<<dd<<endl;for(i=1;i<=dd;i++) cout<<dn[i]<<" ";puts("");
    for(i=1;i<=dd;i++)
    {
	p=zh(1,dn[i]%m),q=zh(1,dn[i%dd+1]%m);
	add(1,p,dn[i]);
	add(p,q,disb(dn[i]%m,dn[i%dd+1]%m));
//	cerr<<"  "<<len[p]<<" "<<q<<endl;
	q=zh(1,((dn[i%dd+1]-n)%m+m)%m);
	if(p!=q) add(p,q,disb(dn[i],((dn[i%dd+1]-n)%m+m)%m));
    }

    d[1]=0;
    que.push(1);
    for(;!que.empty();)
    {
	q=que.front();
	que.pop();
	in[q]=0;
	for(p=first[q];p!=-1;p=bn[p].next)
	{
	    t=bn[p].to;
	    if(d[t]<=d[q]+bn[p].quan) continue;
	    d[t]=d[q]+bn[p].quan;
	    if(!in[t])
	    {
		in[t]=1;
		que.push(t);
	    }
	}
    }
    for(i=1;i<=tt;i++) if(!ok[i]) res=max(res,d[i]);
    for(i=1;i<=tt;i++) first[i]=-1,d[i]=INF,ok[i]=0;
    return res;
}

int main()
{
    memset(first,-1,sizeof(first));
    memset(d,0x3f,sizeof(d));
    ll i,j,p,q;
    cin>>n>>m;
    g=eg(n,m,x,y);
    if(g>200000)
    {
	puts("-1");
	return 0;
    }
    p=m/g,q=n/g;
    x=(x%p+p)%p;
    y=(y%q+q)%q;
//    cerr<<" "<<x<<" "<<y<<endl;
    cin>>p;for(i=1;i<=p;i++) scanf("%lld",&q),a[q%g].push_back(q);
    cin>>p;for(i=1;i<=p;i++) scanf("%lld",&q),b[q%g].push_back(q);
    for(i=0;i<g;i++)
    {
	if(!a[i].size() && !b[i].size())
	{
	    puts("-1");
	    return 0;
	}
	ans=max(ans,calc(i));
    }
    cout<<ans;
}