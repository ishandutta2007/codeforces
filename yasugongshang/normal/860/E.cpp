#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
const int N=500005;
vector<int> v[N];
ll tree[N<<2],ans[N],c2[N];
int nedge,c1[N],wson[N],ed[N<<1],nextt[N<<1],son[N],lazy[N<<2],peo[N],deep[N],ti,n,pos[N],father[N],in[N],top[N];
void aedge(int a,int b){
    nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;
}
#define lowbit(i) i&-i
inline void add(int x,int v){
	ll xx=(ll)(x-1)*v;
    for(int i=x;i<=n;i+=lowbit(i)) c1[i]+=v,c2[i]+=xx;
}
inline ll getsum(ll pos){
    ll ret1=0,ret2=0;
    for(int i=pos;i;i-=lowbit(i)){ret1+=c1[i]; ret2-=c2[i];}
    return ret1*pos+ret2;
}
inline void Add(int l,int r){
	add(l,1); add(r+1,-1);
}
inline ll ask(int l,int r){
	return getsum(r)-getsum(l-1);
}
void dfs1(int p){
    peo[p]=1; wson[p]=-1;
    for(int i=son[p];i;i=nextt[i]){
        deep[ed[i]]=deep[p]+1; father[ed[i]]=p;
        dfs1(ed[i]); peo[p]+=peo[ed[i]];
        if(wson[p]==-1||peo[ed[i]]>peo[wson[p]])wson[p]=ed[i];
    }
}
void dfs2(int p){
    pos[in[p]=++ti]=p;
    if(p==wson[father[p]])top[p]=top[father[p]]; else top[p]=p;
    if(wson[p]!=-1)dfs2(wson[p]);
    for(int i=son[p];i;i=nextt[i])if(ed[i]!=wson[p])dfs2(ed[i]);
}
void init(int s){
    nedge=deep[s]=ti=0; dfs1(s); dfs2(s); 
}
void update(int pos){
	for(int i=pos;i;i=father[top[i]]){
		Add(in[top[i]],in[i]);
	}
}
ll get(int pos){
	ll ans=0;
	for(int i=pos;i;i=father[top[i]]){
		ans+=ask(in[top[i]],in[i]);
	}
	return ans;
}
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(ll a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
signed main(){
	n=read(); int gen;
	for(int i=1;i<=n;i++)father[i]=read();
	for(int i=1;i<=n;i++)if(father[i])aedge(father[i],i); else gen=i;
	init(gen);
	for(int i=1;i<=n;i++)v[deep[i]].push_back(i);
	for(int i=0;i<n;i++){
		for(unsigned j=0;j<v[i].size();j++)update(v[i][j]);
		//cout<<get(2)<<endl;
		for(unsigned j=0;j<v[i].size();j++)ans[v[i][j]]=get(v[i][j])-deep[v[i][j]]-1;
	}
	for(int i=1;i<=n;i++){
		write(ans[i]); putchar(' ');
	}
}