#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
typedef vector<int>V;
const int N=1e5+5,B=150;
int n,m,q,i,u,v,l,r;
char c,fc[N];
string s[N];
struct tree{
	vector<pair<int,char>>e[N];
	int dad[N],dcnt,sz[N],ma[N],top[N],dep[N],dfn[N],be[N],en[N];
	void dfs1(int x,int fa){
		dad[x]=fa;sz[x]=1;dep[x]=dep[fa]+1;
		for(auto u:e[x]){
			int y=u.first;if(y==fa)continue;
			fc[y]=u.second;dfs1(y,x);sz[x]+=sz[y];if(sz[y]>sz[ma[x]])ma[x]=y;
		}
	}
	void dfs2(int x,int fa){
		dfn[be[x]=++dcnt]=x;
		if(ma[x])top[ma[x]]=top[x],dfs2(ma[x],x);
		for(auto u:e[x]){
			int y=u.first;if(y==fa || y==ma[x])continue;
			top[y]=y;dfs2(y,x);
		}
		en[x]=dcnt;
	}
	inline vector<P>getpath(int u,int v){
		vector<P>A,B;int x,y;
		for(;x=top[u],y=top[v],x!=y;){
			if(dep[x]>dep[y])A.push_back({be[u],be[x]}),u=dad[x];
				else B.push_back({be[y],be[v]}),v=dad[y];
		}
		A.push_back({be[u],be[v]});
		reverse(B.begin(),B.end());A.insert(A.end(),B.begin(),B.end());
		return A;
	}
	P pos[B+5][N];
	int bo[N];
	void dfs3(int x,int fa,P*aa);
	inline void init();
}T;
struct node{int l,r,s;}t[N*20];int tcnt;
void ins(int x,int&y,int l,int r,int k){
	t[y=++tcnt]=t[x];++t[y].s;if(l==r)return;
	int m=l+r>>1;if(k<=m)ins(t[x].l,t[y].l,l,m,k);else ins(t[x].r,t[y].r,m+1,r,k);
}
int ask(int x,int y,int l,int r,int ql,int qr){
	if(ql<=l && r<=qr)return t[y].s-t[x].s;
	int m=l+r>>1,ass=0;
	if(ql<=m)ass+=ask(t[x].l,t[y].l,l,m,ql,qr);
	if(m<qr)ass+=ask(t[x].r,t[y].r,m+1,r,ql,qr);
	return ass;
}
int cnt3;
struct SAM{
	static const int M=N*2;
	int ch[M][26],pre[M],step[M],xb;
	int be[M],en[M],dcnt,rt[M];
	vector<int>col[M],e[M];
	int ch2[M][26];
	SAM(){xb=1;memset(ch[1],0,104);}
	char*ee[M];
	inline void build(string&s,int id){
		int p,q,np,nq,lst=1,i,x;
		reverse(s.begin(),s.end());
		for(i=0;i<s.size();++i){
			x=s[i]-'a';
			p=lst;
			if(ch[p][x]){
				q=ch[p][x];
				if(step[p]+1!=step[q]){
					step[nq=++xb]=step[p]+1;col[nq].push_back(id);lst=nq;
					ee[nq]=ee[q];
					memcpy(ch[nq],ch[q],104);
					ee[q]-=step[nq]-step[pre[q]];
					pre[nq]=pre[q];pre[q]=nq;
					for(;p && ch[p][x]==q;p=pre[p])ch[p][x]=nq;
				}else col[q].push_back(id),lst=q;
				continue;
			}
			step[np=++xb]=step[p]+1;col[np].push_back(id);
			memset(ch[np],0,104);
			for(;p && !ch[p][x];p=pre[p])ch[p][x]=np;
			if(p){
				q=ch[p][x];
				if(step[p]+1!=step[q]){
					step[nq=++xb]=step[p]+1;
					ee[nq]=ee[q];
					memcpy(ch[nq],ch[q],104);
					ee[q]-=step[nq]-step[pre[q]];
					pre[nq]=pre[q];pre[q]=pre[np]=nq;
					for(;p && ch[p][x]==q;p=pre[p])ch[p][x]=nq;
				}else pre[np]=q;
			}else pre[np]=1;
			ee[np]=&s[step[np]-step[pre[np]]-1];
			lst=np;
		}
	}
	void dfs(int x){
		be[x]=++dcnt;rt[dcnt]=rt[dcnt-1];
		for(int u:col[x])ins(rt[dcnt],rt[dcnt],1,m,u);
		for(int y:e[x])ch2[x][*ee[y]-'a']=y;
		for(int i=0;i<26;++i)if(ch2[x][i]){
//cerr<<x<<' '<<ch2[x][i]<<' ';
//for(int j=0;j<step[ch2[x][i]]-step[x];++j)cerr<<ee[ch2[x][i]][-j];
//cerr<<endl;
			dfs(ch2[x][i]);
		}
		en[x]=dcnt;
	}
	inline void init(){
		for(int i=2;i<=xb;++i)e[pre[i]].push_back(i);
		dfs(1);
	}
	inline void go1(P&u,int x){
		int a,b;tie(a,b)=u;
		if(b!=-1){
++cnt3;
			if(ch[a][x])a=ch[a][x],++b;else b=-1;
			u={a,b};
		}
	}
	inline void go2(P&u,int x){
		int a,b;tie(a,b)=u;
		if(b!=-1){
			if(b==step[a]){
				a=ch2[a][x];++b;
				if(!a)b=-1;
			}else{
				if(ee[a][-(b-step[pre[a]])]-'a'!=x)b=-1;
					else ++b;
			}
			u={a,b};
		}
	}
}S;
void tree::dfs3(int x,int fa,P*aa){
	for(auto uu:e[x]){
		int y;char c;tie(y,c)=uu;if(y==fa)continue;
		aa[y]=aa[x];
		S.go1(aa[y],c-'a');
		dfs3(y,x,aa);
	}
}
inline void tree::init(){
	dfs1(1,0);top[1]=1;dfs2(1,0);
	static int pp[N];int i,j;mt19937 R(114514);
	for(i=1;i<=n;++i)pp[i]=i,swap(pp[i],pp[R()%i+1]);
//exit(0);
	for(i=1;i<=min(n,B);++i){
		int x=pp[i],y;bo[be[x]]=i;
		pos[i][x]={1,0};
		//dfs3(x,0,pos[i]);
		for(;y=dad[x];x=y)pos[i][y]=pos[i][x],S.go1(pos[i][y],fc[x]-'a');
		for(j=1;j<=n;++j){
			y=dfn[j];
			if(!pos[i][y].first)x=dad[y],pos[i][y]=pos[i][x],S.go1(pos[i][y],fc[y]-'a');
		}
	}
}
inline int dir(const P&u){
	int x,y;tie(x,y)=u;
	return x<y?1:-1;
}
int main(){
//	freopen("1","r",stdin);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;
	for(i=1;i<n;++i)cin>>u>>v>>c,T.e[u].push_back({v,c}),T.e[v].push_back({u,c});
	for(i=1;i<=m;++i)cin>>s[i],S.build(s[i],i);
	S.init();T.init();
//cerr<<clock()<<endl;
int cnt1=0,cnt2=0;
	for(;q--;){
		cin>>u>>v>>l>>r;
		auto ve=T.getpath(u,v);
		int i,j;
		for(i=ve.size()-1,j=ve[i].second;;){
			if(T.bo[j] || j==T.be[u])break;
++cnt1;
			if(j==ve[i].first)j=ve[--i].second;else j-=dir(ve[i]);
		}
		P a=j==T.be[u]?P{1,0}:T.pos[T.bo[j]][u];
		if(a.second==-1){cout<<'0'<<'\n';continue;}
		for(;i+1<ve.size() || j!=ve[i].second;){
			int nj=j==ve[i].second?ve[i+1].first:j+dir(ve[i]),x=T.dfn[j],y=T.dfn[nj];
++cnt2;
			S.go2(a,(x==T.dad[y]?fc[y]:fc[x])-'a');if(j==ve[i].second)++i;j=nj;
		}
		tie(u,v)=a;
		cout<<(v==-1?0:ask(S.rt[S.be[u]-1],S.rt[S.en[u]],1,m,l,r))<<'\n';
	}
//cerr<<cnt1<<' '<<cnt2<<' '<<cnt3<<endl;
}