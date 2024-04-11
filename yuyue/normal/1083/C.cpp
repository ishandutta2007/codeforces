#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
struct Tree{
	int n,rt=1;
	vector<int> v[M];
	void add(int x,int y){
		v[x].pb(y);
		v[y].pb(x);
	}
	int dep[M],a[M],lg[M*2],tot,st[22][M*2],L[M],dfn[M],sz[M],dfnt;
	void dfs(int x,int fa){
		dep[x]=dep[fa]+1; st[0][++tot]=x; L[x]=tot; dfn[x]=++dfnt; sz[x]=1;
		for (int y:v[x]){
			if (y^fa){
				dfs(y,x);
				sz[x]+=sz[y];
				st[0][++tot]=x;
			}
		}
	}
	int _min(int x,int y){
		return dep[x]<dep[y] ? x : y;
	}
	int lca(int x,int y){
		int l=L[x],r=L[y];
		if (l>r) swap(l,r);
		int le=lg[r-l+1];
		return _min(st[le][l],st[le][r-(1<<le)+1]);
	}
	void init(int _n){
		n=_n; tot=0;
		dfs(rt,0);
		F(i,2,n*2) lg[i]=lg[i>>1]+1;
		F(i,1,20) F(j,1,tot-(1<<i)+1) st[i][j]=_min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	}
	bool insub(int x,int y){
		return dfn[y]<=dfn[x]+sz[x]-1 && dfn[y]>=dfn[x];
	}
}T;
struct chain{
	int x,y;
}t[M<<2];
bool cmp(int x,int y){
	return T.dfn[x]<T.dfn[y];
}
int de[M],p[M],rp[M];
chain operator +(chain A,chain B){
	if (A.x==-1 || B.x==-1) return (chain){-1,-1};
	vector<int> d; d.pb(A.x); d.pb(A.y);
	d.pb(B.x); d.pb(B.y);
	sort(d.begin(),d.end(),cmp);
	int N=unique(d.begin(),d.end())-d.begin();
	d.resize(N);
	F(i,1,N-1) d.pb(T.lca(d[i],d[i-1]));
	sort(d.begin(),d.end(),cmp);
	N=unique(d.begin(),d.end())-d.begin();
	d.resize(N);
	if (d.size()==1) return (chain){d[0],d[0]};
	static int stk[10];
	int tp=0;
	for (int x:d){
		while (tp && !T.insub(stk[tp],x)) tp--;
		if (tp) de[stk[tp]]++,de[x]++;
		stk[++tp]=x;
	}
	bool fl=0;
	int L=0,R=0;
	for (int x:d){
		if (de[x]>2) fl=1;
		else if (de[x]==1){
			if (!L) L=x;
			else R=x;
		}
		de[x]=0;
	}
	if (fl) return (chain){-1,-1};
	return (chain){L,R};
}
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
void build(int x,int l,int r){
	if (l==r){
		t[x]=(chain){rp[l],rp[l]};
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	t[x]=t[lc]+t[rc];
}
void upd(int x,int l,int r,int p){
	if (l==r){
		t[x]=(chain){rp[l],rp[l]};
		return ;
	}
	if (p<=mid) upd(lc,l,mid,p);
	else upd(rc,mid+1,r,p);
	t[x]=t[lc]+t[rc];
}
chain cur;
int qry(int x,int l,int r){
	if ((cur+t[x]).x!=-1) return r;
	if (l==r) return l-1;
	if ((cur+t[lc]).x!=-1){
		cur=cur+t[lc];
		return qry(rc,mid+1,r);
	}
	return qry(lc,l,mid);
}
int n;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	F(i,1,n) p[i]=read(),rp[p[i]]=i;
	F(i,2,n){
		int x=read();
		T.add(x,i);
	}
	T.init(n);
	build(1,0,n-1);
	int Q=read();
	while (Q--){
		int op=read();
		if (op==1){
			int x=read(),y=read();
			swap(p[x],p[y]);
			swap(rp[p[x]],rp[p[y]]);
			upd(1,0,n-1,p[x]);
			upd(1,0,n-1,p[y]);
		}
		else{
			cur=(chain){rp[0],rp[0]};
			int tmp=qry(1,0,n-1);
			cout<<tmp+1<<"\n";
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
*/