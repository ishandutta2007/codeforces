#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
const long long N=200005,oo=4e18;
long long ans[N],a[N];
long long nedge,wson[N],ed[N<<1],nextt[N<<1],son[N],lazy[N<<2],peo[N],deep[N],ti,n,pos[N],father[N],in[N],top[N];
#define PI pair<long long,long long>
PI tree[N<<2];
priority_queue<long long> que[N];
inline void aedge(long long a,long long b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;
}
inline void cao(long long nod,long long x){
	tree[nod].first+=x;
}
inline void pushdown(long long nod){
	if(!lazy[nod])return;
	lazy[nod<<1]+=lazy[nod]; lazy[nod<<1|1]+=lazy[nod]; cao(nod<<1,lazy[nod]); cao(nod<<1|1,lazy[nod]); lazy[nod]=0;
}
inline PI ask(long long l,long long r,long long i,long long j,long long nod){long long mid=(l+r)>>1;
	if (l==i&&j==r) return tree[nod]; pushdown(nod);
	if (j<=mid) return ask(l,mid,i,j,nod<<1);
	else if(i>mid) return ask(mid+1,r,i,j,nod<<1|1);
	return min(ask(l,mid,i,mid,nod<<1),ask(mid+1,r,mid+1,j,nod<<1|1));
}
inline void insert(long long l,long long r,long long i,long long j,long long s,long long nod){
    long long mid=(l+r)>>1;
	if(l==i&&r==j){
		lazy[nod]+=s; cao(nod,s); return;
	}
	pushdown(nod);
    if(j<=mid)insert(l,mid,i,j,s,nod<<1); else
    if(i>mid)insert(mid+1,r,i,j,s,nod<<1|1); else{
    insert(l,mid,i,mid,s,nod<<1); insert(mid+1,r,mid+1,j,s,nod<<1|1);
	}
	tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
}
inline void build(long long l,long long r,long long nod){
	long long mid=(l+r)>>1; lazy[nod]=0;
	if (l==r){tree[nod]=mp(-que[pos[l]].top(),pos[l]); return;}
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	tree[nod]=min(tree[nod<<1],tree[nod<<1|1]);
}
void dfs1(long long p){
	peo[p]=1; wson[p]=-1;
	for(long long i=son[p];i;i=nextt[i])if(ed[i]!=father[p]){
		deep[ed[i]]=deep[p]+1; father[ed[i]]=p;
		dfs1(ed[i]); peo[p]+=peo[ed[i]];
		if(wson[p]==-1||peo[ed[i]]>peo[wson[p]])wson[p]=ed[i];
	}
}
void dfs2(long long p){
	pos[in[p]=++ti]=p;
	if(p==wson[father[p]])top[p]=top[father[p]]; else top[p]=p;
	if(wson[p]!=-1)dfs2(wson[p]);
	for(long long i=son[p];i;i=nextt[i])if(ed[i]!=father[p]&&ed[i]!=wson[p])dfs2(ed[i]);
}
void init(long long s){
	nedge=deep[s]=ti=0; dfs1(s); dfs2(s); build(1,n,1);
}
PI query1(long long u,long long v){
	PI ans=mp(oo,0);
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]])swap(u,v);
		ans=min(ans,ask(1,n,in[top[u]],in[u],1)); 
		u=father[top[u]];
	}
	if(deep[u]>deep[v])swap(u,v);
	return min(ans,ask(1,n,in[u],in[v],1));
}
inline long long read(){
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
int main(){
	n=read(); long long m=read(),q=read();
	for(long long i=1;i<n;i++){
		long long a=read(),b=read(); aedge(a,b); aedge(b,a);
	}
	for(int i=1;i<=n;i++)que[i].push(-oo);
	for(long long i=1;i<=m;i++)que[read()].push(-i);
	init(1);
	while(q--){
		long long op=read(); 
		if(op==1){
			long long u=read(),v=read(),k=read(),tot=0;
			for(long long i=1;i<=k;i++){
				pair<long long,long long> t=query1(u,v);
				if(t.first>=oo)break; 
				//cout<<-que[t.second].top()<<endl;
				ans[++tot]=-que[t.second].top();
				que[t.second].pop();
				insert(1,n,in[t.second],in[t.second],-que[t.second].top()-ans[tot],1);
			}
			write(tot); putchar(' ');
			for(long long i=1;i<=tot;i++){
				write(ans[i]); putchar(' ');
			}
			puts("");
		}else{
			long long x=read(),k=read();
			insert(1,n,in[x],in[x]+peo[x]-1,k,1);
		}
	}
}