#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
    int x = 0; char ch = gc(); bool positive = 1;
    for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
const int N=200005,oo=1e9;
int ans[N],fa[N];
pair<PI,int> a[N];
int nedge,wson[N],ed[N],nextt[N],son[N],tree[N<<2],lazy[N<<2],peo[N],deep[N],ti,n,m,pos[N],father[N],in[N],top[N];
inline void aedge(int a,int b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;
}
inline void cao(int nod,int r,int x){
	tree[nod]=x+deep[pos[r]]*2; lazy[nod]=x;
	//if(x==11)cout<<pos[r]<<" "<<tree[nod]<<" "<<nod<<endl;
}
inline void pushdown(int nod,int l,int r){
	if(lazy[nod]==-oo)return; int mid=(l+r)>>1; cao(nod<<1,mid,lazy[nod]); cao(nod<<1|1,r,lazy[nod]); lazy[nod]=-oo;
}
inline int ask(int l,int r,int i,int j,int s,int nod){
	//if(s==11)cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<tree[nod]<<" "<<lazy[nod]<<" "<<nod<<endl;
	if(l>1&&tree[nod]<=s)return 0;
	if (l==r) return pos[l];
	pushdown(nod,l,r);
	int mid=(l+r)>>1;
	if (j<=mid) return ask(l,mid,i,j,s,nod<<1);
	else if(i>mid) return ask(mid+1,r,i,j,s,nod<<1|1);
	int t=ask(mid+1,r,mid+1,j,s,nod<<1|1); if(t)return t;
	return ask(l,mid,i,mid,s,nod<<1);
}
inline void insert(int l,int r,int i,int j,int s,int nod){
	//if(nod==1)cout<<l<<" "<<r<<" "<<i<<" "<<j<<endl;
	if(l==i&&r==j){
		lazy[nod]=s; cao(nod,r,s); return;
	}
	pushdown(nod,l,r);
	int mid=(l+r)>>1;
    if(j<=mid)insert(l,mid,i,j,s,nod<<1); else
    if(i>mid)insert(mid+1,r,i,j,s,nod<<1|1); else{
    	insert(l,mid,i,mid,s,nod<<1); insert(mid+1,r,mid+1,j,s,nod<<1|1);
	}
	tree[nod]=max(tree[nod<<1],tree[nod<<1|1]);
}
void dfs1(int p){
	peo[p]=1; wson[p]=-1;
	for(int i=son[p];i;i=nextt[i]){
		deep[ed[i]]=deep[p]+1;
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
inline bool cmp(pair<PI,int> a,pair<PI,int> b){
	return a.first.second+deep[a.first.first]==b.first.second+deep[b.first.first]?a.first.first<b.first.first:a.first.second+deep[a.first.first]<b.first.second+deep[b.first.first];
}
void update(int u,int v,int x){
    while(top[u]!=top[v]){
        insert(1,n,in[top[u]],in[u],x,1);
        u=father[top[u]];
    }
    if(u!=v)insert(1,n,in[v]+1,in[u],x,1);
}
int query(int u,int t){
    int ans=deep[u]+t;
    while(1){
        int t=ask(1,n,in[top[u]],in[u],ans,1);if(t)return t;
        u=father[top[u]];
    }
}
int main(){
//	freopen("tree.in","r",stdin); freopen("tree.out","w",stdout);
	n=read()+1; m=read();
	for(int i=1;i<(N<<2);i++)lazy[i]=-oo;
	for(int i=2;i<=n;i++){
		deep[i]=deep[father[i]=read()+1]+1; aedge(father[i],i);
	}
	dfs1(1); dfs2(1);
	for(int i=1;i<=m;i++){
		a[i].first.first=read()+1; a[i].first.second=read(); a[i].second=i;
	}
	//for(int i=1;i<=m;i++)cout<<deep[a[i].first.first]+a[i].first
	sort(&a[1],&a[m+1],cmp);
	for(int i=1;i<=m;i++){
		//writeln(a[i].first.first);
		//cout<<a[i].first.first<<" "<<" "<<ans[a[i].second]<<" "<<deep[a[i].first.first]<<" "<<a[i].first.second<<endl;
		int t=query(a[i].first.first,a[i].first.second);
		ans[a[i].second]=a[i].first.second+(deep[a[i].first.first]-deep[t])*2;
		//cout<<ans[a[i].second]-deep[a[i].first.first]<<" "<<a[i].first.second+deep[a[i].first.first]<<" "<<deep[a[i].first.first]<<endl;
		//writeln(ans[a[i].second]-deep[a[i].first.first]);
		update(a[i].first.first,t,ans[a[i].second]-deep[a[i].first.first]);
	}
	for(int i=1;i<=m;i++)write(ans[i]),putchar(' ');
}