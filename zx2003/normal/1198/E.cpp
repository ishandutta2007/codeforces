#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll min(const ll&a,const ll&b){return a<b?a:b;}
struct graph{
	static const ll N=1100,M=3e4;
	struct edge{ll to,next,f;}e[M<<1];
	ll h[N],cur[N],xb;
	inline void addedge(ll x,ll y,ll z){
		e[++xb]=(edge){y,h[x],z};h[x]=xb;
		e[++xb]=(edge){x,h[y],0};h[y]=xb;
	}
	ll S,T,d[N],n;
	inline bool bfs(){
		static ll q[N];ll t=0,w=1;q[1]=S;
		memset(d+1,0,n<<3);d[S]=1;
		for(;t<w;){
			ll u=q[++t];
			for(ll i=h[u];i;i=e[i].next)if(e[i].f && !d[e[i].to])
				d[e[i].to]=d[u]+1,q[++w]=e[i].to;
		}
		return d[T];
	}
	ll dfs(ll x,ll f){
		if(x==T)return f;
		ll ans=0,&i=cur[x],t;
		for(;i;i=e[i].next)if(e[i].f && d[e[i].to]==d[x]+1){
			if(t=dfs(e[i].to,min(f,e[i].f))){
				ans+=t,e[i].f-=t;e[i^1].f+=t;f-=t;
				if(!f)break;
			}
		}
		return ans;
	}
	inline ll dinic(ll s,ll t){
		ll ans=0;S=s;T=t;
		for(;bfs();ans+=dfs(s,1<<30))memcpy(cur+1,h+1,n<<3);
		return ans;
	}
}g;
const ll N=105;
ll n,m,xx1[N],yy1[N],xx2[N],yy2[N],A,B,i,j,k;
vector<ll>x,y;
bool bb[N][N];
signed main(){
//	freopen("1","r",stdin);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;if(m==0)return cout<<0<<endl,0;
	for(i=1;i<=m;++i){
		cin>>xx1[i]>>yy1[i]>>xx2[i]>>yy2[i];
		x.push_back(xx1[i]);
		x.push_back(++xx2[i]);
		y.push_back(yy1[i]);
		y.push_back(++yy2[i]);
	}
	sort(x.begin(),x.end());x.erase(unique(x.begin(),x.end()),x.end());
	sort(y.begin(),y.end());y.erase(unique(y.begin(),y.end()),y.end());
	A=x.size()-1;B=y.size()-1;
	for(i=1;i<=m;++i){
		xx1[i]=lower_bound(x.begin(),x.end(),xx1[i])-x.begin()+1;
		xx2[i]=lower_bound(x.begin(),x.end(),xx2[i])-x.begin()+1;
		yy1[i]=lower_bound(y.begin(),y.end(),yy1[i])-y.begin()+1;
		yy2[i]=lower_bound(y.begin(),y.end(),yy2[i])-y.begin()+1;
		for(j=xx1[i];j<xx2[i];++j)for(k=yy1[i];k<yy2[i];++k)bb[j][k]=1;
	}
	g.n=2+A+B;g.xb=1;
	for(i=1;i<=A;++i)g.addedge(1,i+2,x[i]-x[i-1]);
	for(i=1;i<=B;++i)g.addedge(i+2+A,2,y[i]-y[i-1]);
	for(i=1;i<=A;++i)for(j=1;j<=B;++j)if(bb[i][j])g.addedge(i+2,j+2+A,1ll<<50);
	cout<<g.dinic(1,2)<<'\n';
	return 0;
}