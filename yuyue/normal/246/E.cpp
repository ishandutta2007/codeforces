#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2e5+10;
unordered_map<string,int> mp;
unordered_map<int,int> s[M]; 
int tt[M],val[M];
int son[M],sz[M],n,m;
int to[M],nxt[M],head[M],cnt; 
vector<pair<int,int> > v[M];
int ans[M],dep[M];
void add(int x,int y){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt;
}
void dfs(int x,int fa){
	sz[x]=1; 
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		dep[y]=dep[x]+1; dfs(y,x); 
		sz[x]+=sz[y];
		if (sz[y]>sz[son[x]]) son[x]=y;
	}
}
void dop(int x,int num,bool op){
	if (op) {
		if (!(s[x][num]++)) tt[x]++;
	}
	else if (!(--s[x][num])) tt[x]--;
}
bool vis[M];
void calc(int x,int fa,bool op){
	dop(dep[x],val[x],op);
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (!vis[y]) calc(y,x,op);
	}
}
void dfs1(int x,int fa,bool keep){
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==son[x]) continue;
		dfs1(y,x,0);
	}
	if (!x) return ;
	if (son[x]) dfs1(son[x],x,1);
	vis[son[x]]=1; calc(x,fa,1);
	F(i,0,SZ(v[x])) {
		ans[v[x][i].second]=tt[dep[x]+v[x][i].first];
	}
	vis[son[x]]=0;
	if (!keep) calc(x,fa,0);
}
int main(){
	n=read();
	int ct=0,rt=0;
	F(i,1,n){
		string st; cin>>st; 
		int x=read();
		if (mp[st]) val[i]=mp[st];
		else val[i]=mp[st]=++ct;
//		cout<<val[i]<<"\n";
		add(x,i);
	}
	dfs(0,-1);
	m=read();
	F(i,1,m){
		int x=read(),k=read();
		v[x].pb(make_pair(k,i));
	}
	dfs1(0,-1,0);
	F(i,1,m){
		cout<<ans[i]<<'\n';
	}
    return 0;
}