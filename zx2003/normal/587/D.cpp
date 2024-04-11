#include<bits/stdc++.h>
using namespace std;
const int N=50005;
namespace tst{
const int V=N*6,E=N*20;
struct edge{int to,next;}e[E];
int h[V],ecnt,dfn[V],low[V],xb,st[V],w,bel[V],scccnt,vcnt;bool b[V];
inline void addedge(int x,int y){e[++ecnt]=(edge){y,h[x]};h[x]=ecnt;}
void dfs(int x){
	st[++w]=x;low[x]=dfn[x]=++xb;
	for(int i=h[x];i;i=e[i].next){
		if(!dfn[e[i].to])dfs(e[i].to);
		if(low[e[i].to]<low[x] && !bel[e[i].to])low[x]=low[e[i].to];
	}
	if(low[x]==dfn[x])for(++scccnt;bel[st[w]]=scccnt,b[st[w]^1]?0:b[st[w]]=1,st[w--]!=x;);
}
inline void ini(int n){vcnt=n;memset(h+1,0,n<<2);ecnt=0;}
inline bool wk(int z){
	int i;
	scccnt=0;memset(dfn+1,0,vcnt<<2);memset(low+1,0,vcnt<<2);memset(bel+1,0,vcnt<<2);memset(b+1,0,vcnt);
	for(i=2;i<=vcnt;++i)if(!dfn[i])dfs(i);
	for(i=1;i<=z;++i)if(bel[i<<1]==bel[i<<1|1])
		return 0;
	return 1;
}
}
struct edge{int c,t,id;};
bool cmp(edge a,edge b){return a.c<b.c || (a.c==b.c && a.t<b.t);}
vector<edge>e[N];
int n,m,i,j,u,v,c,t,L,R=1e9,M,s[N];
inline bool check(int x){
	tst::ini(m*6+1);
	for(i=1;i<=n;++i){
		for(j=0;j+1<e[i].size();++j){
			tst::addedge(2+m*2+s[i-1]+j,2+m*2+s[i-1]+j+1);
			tst::addedge(2+m*4+s[i-1]+j+1,2+m*4+s[i-1]+j);
			if(e[i][j].c==e[i][j+1].c){
				if(e[i][j+1].t>x)tst::addedge(e[i][j].id<<1,e[i][j].id<<1|1);else 
					tst::addedge(e[i][j].id<<1,e[i][j+1].id<<1|1),
					tst::addedge(e[i][j+1].id<<1,e[i][j].id<<1|1);
			}
		}
		for(j=0;j<e[i].size();++j){
			tst::addedge(2+m*2+s[i-1]+j,e[i][j].id<<1),tst::addedge(2+m*4+s[i-1]+j,e[i][j].id<<1);
			if(j>0)tst::addedge(e[i][j].id<<1|1,2+m*4+s[i-1]+j-1);
			if(j+1<e[i].size())tst::addedge(e[i][j].id<<1|1,2+m*2+s[i-1]+j+1);
		}
	}
	return tst::wk(m);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;for(i=1;i<=m;++i)cin>>u>>v>>c>>t,e[u].push_back((edge){c,t,i}),e[v].push_back((edge){c,t,i});
	for(i=1;i<=n;++i){
		sort(e[i].begin(),e[i].end(),cmp),s[i]=s[i-1]+e[i].size();
		for(j=0;j+2<e[i].size();++j)if(e[i][j].c==e[i][j+2].c){cout<<"No\n";return 0;}
		for(j=0;j+1<e[i].size();++j)if(e[i][j].c==e[i][j+1].c)L=max(L,e[i][j].t);
	}
	for(;L<R;)M=L+R>>1,check(M)?R=M:L=M+1;
	if(!check(L))cout<<"No\n";else{
		vector<int>ans;
		for(i=3;i<=m*2+1;i+=2)if(tst::b[i])ans.push_back(i/2);
		cout<<"Yes\n"<<L<<' '<<ans.size()<<'\n';
		for(int x:ans)cout<<x<<' ';cout<<endl;
	}
	return 0;
}