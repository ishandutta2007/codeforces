#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
const int N=1e5+5,M=2e5+5,mo1=993244853,mo2=1e9+9;
struct P{int x,y;}mi[N];
inline P operator*(const P&a,const P&b){return (P){int(1ll*a.x*b.x%mo1),int(1ll*a.y*b.y%mo2)};}
inline P operator+(const P&a,const P&b){return (P){(a.x+b.x)%mo1,(a.y+b.y)%mo2};}
inline P operator-(const P&a,const P&b){return (P){(a.x+mo1-b.x)%mo1,(a.y+mo2-b.y)%mo2};}
inline bool operator==(const P&a,const P&b){return a.x==b.x && a.y==b.y;}
int hib[N];
int n,m,q,ans[N],x[N],y[N],z[N],l[N],i,p1[N],p2[N];
struct que{int x,i,k;};
struct BIT{
	int a[M],n;
	inline void ini(int nn){n=nn;memset(a+1,0,n<<2);}
	inline void add(int x,int v){for(;x<=n;x+=x&-x)a[x]+=v;}
	inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=a[x];return ans;}
}bi;
template<size_t N>struct tree{
	int n,be[N],en[N],dcnt,dfn[N],top[N],sz[N],ma[N],dad[N],dep[N];
	V e[N];
	void dfs1(int x,int fa){
		dfn[be[x]=++dcnt]=x;sz[x]=1;dad[x]=fa;dep[x]=dep[fa]+1;
		for(int y:e[x])if(y!=fa){dfs1(y,x);sz[x]+=sz[y];if(sz[y]>sz[ma[x]])ma[x]=y;}
		en[x]=dcnt;
	}
	inline void gettop(int*top,int*ma){top[1]=1;for(int i=2,x;i<=n;++i)x=dfn[i],top[x]=ma[dad[x]]==x?top[dad[x]]:x;}
	inline void pre1(){dfs1(1,0);gettop(top,ma);}
	inline int lca(int x,int y){
		for(;top[x]!=top[y];y=dad[top[y]])if(dep[top[x]]>dep[top[y]])swap(x,y);
		return dep[x]<dep[y]?x:y;
	}
};
struct GBT:tree<M>{
	int ch[M][2],qsz[M],son[M][26],rt,wd[M],bel[M];P su[M];
	inline void pre2(){
		int i;
		pre1();
		for(i=1;i<=n;++i)qsz[i]=sz[i]-sz[ma[i]];
		for(i=1;i<=n;++i)if(top[i]==i){
			static int st[N],suu[N];int w,x,j;
			for(x=i,w=0;x;x=ma[x])st[++w]=x;
			for(j=1;j<=w;++j)suu[j]=qsz[st[j-1]]+suu[j-1];
			function<int(int,int)>build=[&](int l,int r){
				if(l==r)return st[l];
				int m,mn=1<<30,i,z;
				for(i=l;i<=r;++i){z=max(suu[i-1]-suu[l-1],suu[r]-suu[i]);if(z<mn)mn=z,m=i;}
				z=st[m];if(l<m)ch[z][0]=build(l,m-1);if(m<r)ch[z][1]=build(m+1,r);
				return z;
			};
			x=build(1,w);for(j=1;j<=w;++j)bel[st[j]]=x;if(i==1)rt=x;
		}
	}
	inline void ini(int nn){
		int i;n=nn;
		for(i=1;i<=n;++i)e[i].clear(),memset(ch[i],0,8),memset(son[i],0,104);dcnt=0;memset(ma+1,0,n<<2);
	}
	inline int find(int x,int l);
}t2;
struct SAM{
	int ch[M][26],pre[M],step[M],xb;
	SAM():xb(1){}
	inline void ins(const string&s){
		int p,q,np,nq,x,i,lst=1;
		for(i=0;i<s.size();++i){
			x=s[i]-'a';p=lst;
			step[np=++xb]=step[p]+1;for(;p && !ch[p][x];p=pre[p])ch[p][x]=np;
			if(p){
				q=ch[p][x];
				if(step[p]+1!=step[q]){
					step[nq=++xb]=step[p]+1;memcpy(ch[nq],ch[q],104);
					pre[nq]=pre[q];pre[q]=pre[np]=nq;
					for(;p && ch[p][x]==q;p=pre[p])ch[p][x]=nq;
				}else pre[np]=q;
			}else pre[np]=1;
			lst=np;
		}
	}
	int le[M][26],be[M],en[M],dfn[M],dcnt;
	vector<int>e[M];
	void dfs(int x){dfn[be[x]=++dcnt]=x;for(int y:e[x])dfs(y);en[x]=dcnt;}
	inline void getdfn(){for(int i=2;i<=xb;++i)e[pre[i]].push_back(i);dfs(1);}
	inline void build1(){
		int i,j,x,y;
		getdfn();
		for(i=0;i<26;++i)if(!ch[1][i])ch[1][i]=1,le[1][i]=0;else le[1][i]=-1;
		for(i=2;i<=xb;++i){
			x=dfn[i];
			for(j=0;j<26;++j)if(!ch[x][j])ch[x][j]=ch[pre[x]][j],y=le[pre[x]][j],le[x][j]=y==-1?step[pre[x]]+1:y;
				else le[x][j]=-1;
		}
	}
	int lstt[M];
	inline void build2(const string&s){
		static P h[N];static int pos[M];int i,x=1,l=s.size();
		h[l+1]=(P){0,0};for(i=l;i;--i)h[i]=h[i+1]*mi[1]+(P){s[i-1]-'a'+1,s[i-1]-'a'+1};
		memset(pos+1,0,xb<<2);memset(lstt+1,0,xb<<2);
		getdfn();
		for(i=0;i<s.size();++i)x=ch[x][s[i]-'a'],lstt[x]=i+1,pos[x]=1;
		for(i=2;i<=xb;++i)x=dfn[i],lstt[x]?0:lstt[x]=lstt[pre[x]];
		for(i=xb;i;--i)x=dfn[i],!pos[x]?pos[x]=pos[e[x][0]]+step[e[x][0]]-step[x]:0;
		t2.ini(xb);
		for(i=2;i<=xb;++i){
			x=pre[i];
			t2.e[x].push_back(i);
			auto geth=[&](int l,int r){return h[l]-h[r+1]*mi[r-l+1];};
			t2.son[x][s[pos[i]+step[i]-step[x]-2]-'a']=i;t2.su[i]=geth(pos[i],pos[i]+step[i]-1);
		}
		t2.pre2();memcpy(t2.wd+1,step+1,xb<<2);
	}
	inline void go(int&u,int&l,char c){c-='a';if(le[u][c]==-1)++l;else l=le[u][c];u=ch[u][c];}
	inline void clear(){for(int i=1;i<=xb;++i)memset(ch[i],0,104),e[i].clear();xb=1;dcnt=0;}
}ss;
struct strr{
	int l,b;
	string s,rs;
	inline void in(){cin>>s;l=s.size();rs=s;reverse(rs.begin(),rs.end());}
	inline void inss(int tp){ss.ins(tp==1?s:rs);b=1;}
	inline void getb(int tp){for(char c:tp==1?s:rs)b=ss.ch[b][c-'a'];}
	vector<int>qq;
	inline void solve();
}s[N];
struct Tree:tree<N>{
	int top2[N],le[N],ma2[N],anc[20][N];
	V up[N],dow[N];
	inline void pre2(){
		int i,j,x;
		for(i=n;i;--i){x=dfn[i];for(int y:e[x])if(y!=dad[x] && le[y]>le[ma2[x]])ma2[x]=y;le[x]=le[ma2[x]]+1;}
		gettop(top2,ma2);
		memcpy(anc[0]+1,dad+1,n<<2);
		for(i=1;i<20;++i)for(j=1;j<=n;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
		for(i=0;i<20;++i)for(j=1;j<=n;++j)anc[i][j]=top2[anc[i][j]];
		for(i=1;i<=n;++i)if(top2[i]==i){
			auto fil=[&](V&v,int l,int*a){v.resize(l);for(j=0,x=i;j<l;++j)v[j]=x,x=a[x];};
			fil(dow[i],le[i],ma2);fil(up[i],min(le[i],dep[i]),dad);
		}
	}
	char fc[N];
	P h[N];
	inline void in(){
		static unordered_map<int,char>mp[N];char c;int i,x,y;
		for(i=1;i<n;++i)cin>>x>>y>>c,e[x].push_back(y),e[y].push_back(x),mp[x][y]=mp[y][x]=c;
		pre1();pre2();for(i=2;i<=n;++i)fc[i]=mp[dad[i]][i];
		for(i=2;i<=n;++i)x=dfn[i],h[x]=h[dad[x]]*mi[1]+(P){fc[x]-'a'+1,fc[x]-'a'+1};
	}
	inline P geth(int x,int y){return h[x]-h[y]*mi[dep[x]-dep[y]];}
	inline int kthfa(int x,int k){
		int y=anc[hib[k]][x],dt=dep[x]-dep[y];
		return k?k<=dt?dow[y][dt-k]:up[y][k-dt]:x;
	}
	vector<que>qu[N];
	void dfs(int x,int fa,int u,int l){
		int uu=l==ss.step[u]?u:ss.pre[u];
		bi.add(ss.be[uu],1);
		for(que z:qu[x])ans[z.i]+=z.k*(bi.ask(ss.en[z.x])-bi.ask(ss.be[z.x]-1));
		for(int y:e[x])if(y!=fa){int nu=u,nl=l;ss.go(nu,nl,fc[y]);dfs(y,x,nu,nl);}
		bi.add(ss.be[uu],-1);
	}
	inline void solve(int*x){
		int i,d,u,v;for(i=1;i<=n;++i)qu[i].clear();bi.ini(ss.xb);
		for(i=1;i<=q;++i)if(d=dep[x[i]]-dep[l[i]],d>=s[z[i]].l)
			u=s[z[i]].b,qu[x[i]].push_back((que){u,i,1}),qu[kthfa(x[i],d-s[z[i]].l+1)].push_back((que){u,i,-1});
		dfs(1,0,1,0);
	}
}t;
inline int GBT::find(int x,int y){
	int u=rt,ret=1,v,l=t.dep[x]-t.dep[y],z;
	for(;;){
		for(v=0;u;)if(wd[u]<=l && t.geth(t.kthfa(x,l-wd[u]),y)==su[u])v=u,u=ch[u][1];else u=ch[u][0];
		if(!v)break;ret=v;if(wd[v]==l)break;
		u=son[v][t.fc[t.kthfa(x,l-wd[v]-1)]-'a'];if(!u || u==ma[v])break;u=bel[u];
	}
	return ret;
}
inline void strr::solve(){
	static V e[N],re[N];static vector<que>qu[N];static int nxt[N],be[N],en[N];int i,j,dcnt=0;
	auto gettree=[&](V*e,const string&s){
		for(i=0;i<=l;++i)e[i].clear();
		for(i=2,j=0;i<=l;++i){
			for(;j && s[j]!=s[i-1];j=nxt[j]);
			nxt[i]=j+=s[j]==s[i-1];
		}
		for(i=1;i<=l;++i)e[nxt[i]].push_back(i);
	};
	gettree(e,s);gettree(re,rs);
	function<void(int)>dfs1=[&](int x){
		be[x]=++dcnt;
		for(int y:re[x])dfs1(y);
		en[x]=dcnt;
	};
	dfs1(0);bi.ini(l+1);for(i=0;i<=l;++i)qu[i].clear();
	ss.ins(s);ss.build2(s);for(int i:qq)p1[i]=ss.lstt[t2.find(x[i],::l[i])];ss.clear();
	ss.ins(rs);ss.build2(rs);for(int i:qq)p2[i]=ss.lstt[t2.find(y[i],::l[i])];ss.clear();
	for(int i:qq)if(p1[i] && p2[i] && p1[i]+p2[i]>=l)qu[p1[i]].push_back((que){p2[i],i,0});
	function<void(int)>dfs2=[&](int x){
		if(0<x && x<l)bi.add(be[l-x],1),bi.add(en[l-x]+1,-1);
		for(que u:qu[x])ans[u.i]+=bi.ask(be[u.x]);
		for(int y:e[x])dfs2(y);
		if(0<x && x<l)bi.add(be[l-x],-1),bi.add(en[l-x]+1,1);
	};
	dfs2(0);
}
int main(){
	for(i=2;i<N;++i)hib[i]=hib[i>>1]+1;mi[0]=(P){1,1};for(i=1;i<N;++i)mi[i]=mi[i-1]*(P){37,29};
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;
	t.n=n;t.in();
	for(i=1;i<=m;++i)s[i].in();
	for(i=1;i<=q;++i)cin>>x[i]>>y[i]>>z[i],l[i]=t.lca(x[i],y[i]);
	for(i=1;i<=m;++i)s[i].inss(1);ss.build1();for(i=1;i<=m;++i)s[i].getb(1);t.solve(y);ss.clear();
	for(i=1;i<=m;++i)s[i].inss(2);ss.build1();for(i=1;i<=m;++i)s[i].getb(2);t.solve(x);ss.clear();
	for(i=1;i<=q;++i)s[z[i]].qq.push_back(i);
	for(i=1;i<=m;++i)s[i].solve();
	for(i=1;i<=q;++i)cout<<ans[i]<<'\n';
	return 0;
}