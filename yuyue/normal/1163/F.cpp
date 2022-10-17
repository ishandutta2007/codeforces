#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#define mp make_pair
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=6e5+10;
const LL inf=1e18;
int X[M],Y[M],W[M],P[M];
int to[M],nxt[M],head[M],w[M],cnt;
void add(int x,int y,int z){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z;
}
int ord[M],pre[M],xu[M],n,m,pid[M];
LL dis[M];
#define pii pair<LL,int> 
priority_queue<pii> q;
void dij(int S){
	F(i,1,n) ord[i]=0,dis[i]=inf;
	dis[S]=0; int tot=0;
	q.push(mp(-dis[S],S));
	while (q.size()){
		int x=q.top().second; q.pop();
		if (ord[x]) continue;
		ord[x]=++tot; xu[tot]=x;
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (dis[y]>dis[x]+w[i]){
				dis[y]=dis[x]+w[i];
				pre[y]=x;
				pid[y]=i;
				q.push(mp(-dis[y],y));
			}
		}
	}
}
int lab[M],Num=0;
struct DT{
	int label[M];
	LL d[M];
	vector<int> rv[M];
	int BG=0,ED=0;
	void init(int S,int T){
		F(i,1,n) label[i]=((S==1 && lab[i]) ? Num-lab[i]+1 : lab[i]),d[i]=dis[i];
		BG=S; ED=T;
		F(i,1,m){
			if (ord[X[i]]<ord[Y[i]]){
				if (dis[X[i]]+W[i]==dis[Y[i]]){
//					v[X[i]].pb(Y[i]);
					rv[Y[i]].pb(X[i]);
				}
			}
			else{
				if (dis[Y[i]]+W[i]==dis[X[i]]){
//					v[Y[i]].pb(X[i]);
					rv[X[i]].pb(Y[i]);
				}
			}
		}
		F(i,1,n){
			int x=xu[i];
			if (label[x]) continue;
			label[x]=1000000000;
			for (int y:rv[x]){
				label[x]=min(label[x],label[y]);
			}
		}
	}
}A,B;
LL a[M];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
LL tg[M<<2];
void build(int x,int l,int r){
	tg[x]=inf;
	if (l==r){
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void upd(int x,int l,int r,int ll,int rr,LL val){
	if (r<ll || l>rr) return ;
	if (ll<=l && r<=rr){
		tg[x]=min(tg[x],val);
		return ;
	}
	upd(lc,l,mid,ll,rr,val);
	upd(rc,mid+1,r,ll,rr,val);
}
void down(int x,int l,int r,LL cur){
	cur=min(cur,tg[x]);
	if (l==r){
		a[l]=cur;
		return ;
	}
	down(lc,l,mid,cur);
	down(rc,mid+1,r,cur);
}
bool vis[M];
int bian[M];
LL E[M]; 
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	n=read(); m=read(); cnt++; int Q=read(); 
	F(i,1,m){
		X[i]=read(); Y[i]=read(); W[i]=read(); //P[i]=read();
		add(X[i],Y[i],W[i]);  
		add(Y[i],X[i],W[i]);
	}
	dij(1);
	if (dis[n]==inf){
		cout<<inf<<"\n";
		return 0;
	}
	for (int x=n;;x=pre[x]){
		lab[x]=++Num;
		a[Num]=P[pid[x]>>1];
		vis[pid[x]>>1]=1;
		bian[pid[x]>>1]=Num;
//		cerr<<x<<" ";
		if (x==1) break;
	}
//	cerr<<"   path \n";
	A.init(1,n);
//	cerr<<A.label[4]<<" !!! \n";
	dij(n);
	B.init(n,1);
	LL SP=dis[1];
//	F(i,1,n) cerr<<ord[i]<<" ";
//	cerr<<"  wow \n"; 
	build(1,1,Num-1);
	F(i,1,m){
		if (vis[i]) continue; 
		int x=X[i],y=Y[i];
		if (ord[x]<ord[y]) swap(x,y);//1-->x-->y-->n
		int l=B.label[y],r=Num-A.label[x];
		LL alter=A.d[x]+B.d[y]+W[i];
//		cerr<<x<<" "<<y<<" "<<l<<" "<<r<<" "<<alter<<"    change \n";
		if (l<=r){
//			F(j,l,r){
//				a[j]=min(a[j],alter-SP);
//			}
			upd(1,1,Num-1,l,r,alter-SP);
		}
		E[i]=alter;
		swap(x,y);
		l=B.label[y],r=Num-A.label[x];
		alter=A.d[x]+B.d[y]+W[i];
		E[i]=min(E[i],alter);
//		cerr<<x<<" "<<y<<" "<<l<<" "<<r<<" "<<alter<<"    change \n";
		if (l<=r){
//			F(j,l,r){
//				a[j]=min(a[j],alter-SP);
//			}
			upd(1,1,Num-1,l,r,alter-SP);
		}
	}
	down(1,1,Num-1,inf);
//	LL ans=0;
//	F(i,1,Num-1){
//		ans=max(a[i]+SP,ans);
//	}
//	cout<<ans<<"\n";
//	cerr<<ans<<"\n";
	F(i,1,Q){
		int id=read(),y=read();
		if (y>=W[id]){
			if (bian[id]){
				cout<<min(SP+y-W[id],SP+a[bian[id]])<<"\n";
			}
			else{
				cout<<SP<<"\n";
			}
		}
		else{
			if (bian[id]){
				cout<<SP+y-W[id]<<"\n";
			}
			else{
				cout<<min(E[id]+y-W[id],SP)<<"\n";
			}
		}
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
6 10
5 1 8 694918370
6 5 2 549545610
1 6 1 119938947
4 2 4 11674792
5 2 1 287641801
2 1 10 26478624
6 5 8 923688048
3 1 5 286345976
3 5 7 953407595
2 5 5 221261918



10 20
6 9 6 650821004
7 10 7 728836615
7 2 10 630432336
8 4 6 961157276
2 6 3 733980152
3 2 8 753610967
1 6 9 329690100
4 8 5 414766923
4 1 1 46629525
8 7 5 107440563
6 9 10 450428971
5 7 9 251355689
7 2 6 180203162
9 8 5 587597696
1 10 2 171446760
1 9 9 657248253
4 6 9 138061892
9 1 1 792128806
9 1 2 448873522
9 2 3 751699785

*/