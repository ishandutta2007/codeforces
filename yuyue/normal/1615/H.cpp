#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1010,E=M*M; 
int n;
const LL inf=1e12;
namespace FLOW{

	int head[M],cur[M],S,T,nxt[E],to[E],cnt;
	LL w[E];
	void add(int x,int y,LL z){
		to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z; 
	}
	void jb(int x,int y,LL z){
		add(x,y,z); add(y,x,0); 
	}
	int q[M],dep[M]; 
	bool bfs(){
		int l=1,r=1; q[1]=S; ms(dep,0); dep[S]=1; 
		while (l<=r){
			int x=q[l++];
			for (int i=head[x];i;i=nxt[i]){
				int y=to[i];
				if (w[i]&&!dep[y]){
					dep[y]=dep[x]+1;
					q[++r]=y; 
				}
			}
		}
		return dep[T];
	}
	LL dfs(int x,LL flow){
		if (x==T || !flow) return flow;
		LL res=flow; 
		for (int &i=cur[x];i;i=nxt[i]){
			int y=to[i];
			if (dep[y]==dep[x]+1 && w[i]){
				LL ff=dfs(y,min(w[i],res));
				res-=ff; w[i]-=ff; w[i^1]+=ff;
				if (!res) return flow;  
			}
		}
		return flow-res;
	}
	void init(){
		cnt=1; ms(head,0); S=0; T=n+1;
	}
	LL MF(){
		LL ret=0;
		while (bfs()){
			memcpy(cur,head,sizeof cur);
			ret+=dfs(S,inf);
		}
//		cerr<<ret<<"\n";
		return ret;
	}
}
vector<int> P[M]; //edge

int ans[M],v[M],a[M],b[M],tp[M],p[M]; 
bool in[M]; 

int m,dfn[M],low[M],tim,stk[M],tpp,SCC,bl[M],sz[M];
vector<int> scc[M];
LL suan(int id,int mid){
	LL val=0;
	for (int x:scc[id]){
		val+=abs(a[x]-mid)-abs(a[x]-mid-1);
	}
	return val;
}
void solve(int l,int r,int ll,int rr){
	if (ll>rr) return ;
	if (l==r){
		F(i,ll,rr) ans[p[i]]=l;  
		return ;
	}
	int mid=(l+r>>1);
	F(i,ll,rr) in[p[i]]=1; 
	FLOW::init();	
	int tmp=0;
//	cerr<<l<<" "<<r<<" "<<mid<<" check\n"; 
	F(i,ll,rr){	
		int x=p[i]; 
		LL val=suan(x,mid);//????
//		cerr<<val<<" "<<v[x]<<" "<<x<<"   val\n";
		if (val>=0) tmp+=val,FLOW::jb(FLOW::S,x,val);
		else FLOW::jb(x,FLOW::T,-val);
		F(j,0,SZ(P[x])){
			int y=P[x][j];
			if (in[y]) FLOW::jb(x,y,inf);
		}
	}
	FLOW::MF();
	int tl=ll,tr=rr; 
	F(i,ll,rr){
		int x=p[i];
		if (FLOW::dep[x]) tp[tr]=x,tr--;
		else tp[tl]=x,tl++; 
	}
	F(i,ll,rr) p[i]=tp[i]; 
	F(i,ll,rr) in[p[i]]=0; 
	solve(l,mid,ll,tl-1); solve(mid+1,r,tr+1,rr);
}
vector<int> ve[M];
void tarjan(int x){
	dfn[x]=low[x]=++tim; stk[++tpp]=x;
	for (int y:ve[x]){
		if (!dfn[y]) tarjan(y),low[x]=min(low[x],low[y]);
		else if (!bl[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if (low[x]==dfn[x]){
		SCC++;
		while (1){
			int y=stk[tpp--]; 
			bl[y]=SCC;
			sz[SCC]++;
			scc[SCC].pb(y);
			v[SCC]=a[y];
			if (y==x) break;
		}
	}
}
bool edge[1010][1010];
void init(){
	F(i,1,n) if (!dfn[i]) tarjan(i);
	F(x,1,n){
		for (int y:ve[x]){
			if (bl[x]^bl[y] && !edge[bl[x]][bl[y]]){
				P[bl[x]].pb(bl[y]);
				edge[bl[x]][bl[y]]=1;
//				cerr<<bl[x]<<" -> "<<bl[y]<<" edge\n";
			}
		}
	}
//	F(i,1,n){
//		cerr<<bl[i]<<" ";
//	}
//	cerr<<"   bl\n";
}
int main(){
//	n=read(); m=read(); 
//	F(i,1,n) cin>>c[i];
//	F(i,1,n) v[i]=read(); 
//	F(i,1,m) a[i]=read(); 
//	F(i,1,m) b[i]=read(); 
//	F(i,1,m){
//		lb.clr();
//		F(j,1,m){
//			if (i!=j){
//				lb.ins(c[a[j]]); 
//			}
//		}
//		F(j,1,n){
//			if (j==a[i]) continue; 
//			int pos=lb.ins(c[j]); 
//			if (pos>=0) P[a[i]].pb(j),lb.d[pos]=0;
//		}
//	}
//	F(i,1,m){
//		lb.clr();
//		F(j,1,m){
//			if (i!=j){
//				lb.ins(c[b[j]]); 
//			}
//		}
//		F(j,1,n){
//			if (j==b[i]) continue; 
//			int pos=lb.ins(c[j]); 
//			if (pos>=0) P[j].pb(b[i]),lb.d[pos]=0;
//		}
//	}
	n=read(); m=read();
	int mx=0;
	F(i,1,n) a[i]=read(),mx=max(mx,a[i]);
	F(i,1,m){
		int x=read(),y=read();
		ve[x].pb(y);
	}
	init();
	
	
	F(i,1,SCC) p[i]=i;
	solve(0,mx,1,SCC); 
	LL finalans=0;
	F(i,1,n) cout<<ans[bl[i]]<<" ",finalans+=abs(a[i]-ans[bl[i]]);
	cout<<"\n"; 
//	cerr<<finalans<<"\n"; 
	return 0;
}