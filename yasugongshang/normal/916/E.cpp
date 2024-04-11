#include<iostream>
#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int dist[N],root=1,q,pos[N],tree[N<<2],lazy[N<<2],in[N],out[N],ti,n,a[N],an[N],nextt[N],son[N],ed[N],dp[N][22],nedge;
inline void aedge(int a,int b){
	nextt[++nedge]=son[a];
	son[a]=nedge;
	ed[nedge]=b;
}
inline void dfs(int p,int fa){
	dp[p][0]=fa; pos[in[p]=++ti]=p; dist[p]=dist[fa]+1;
	for(int i=son[p];i;i=nextt[i])if(ed[i]!=fa){
		dfs(ed[i],p);
	}
	out[p]=ti;
}
inline void cao(int nod,int l,int r,int x){
	tree[nod]+=x*(r-l+1);
}
inline void pushdown(int nod,int l,int r){
	if(!lazy[nod])return; int mid=(l+r)>>1;
	lazy[nod<<1]+=lazy[nod]; lazy[nod<<1|1]+=lazy[nod]; cao(nod<<1,l,mid,lazy[nod]); cao(nod<<1|1,mid+1,r,lazy[nod]); lazy[nod]=0;
}
inline void insert(int l,int r,int i,int j,int s,int nod){
    int mid=(l+r)>>1;
	if(l==i&&r==j){
		lazy[nod]+=s; cao(nod,l,r,s); return;
	}
    pushdown(nod,l,r);
    if(j<=mid)insert(l,mid,i,j,s,nod<<1); else
    if(i>mid)insert(mid+1,r,i,j,s,nod<<1|1); else{
    	insert(l,mid,i,mid,s,nod<<1); insert(mid+1,r,mid+1,j,s,nod<<1|1);
	}
	tree[nod]=tree[nod<<1]+tree[nod<<1|1];
}
inline int ask(int l,int r,int i,int j,int nod){
	if(l==i&&r==j)return tree[nod];
    int mid=(l+r)>>1;
    pushdown(nod,l,r);
    if(j<=mid)return ask(l,mid,i,j,nod<<1); else
    if(i>mid)return ask(mid+1,r,i,j,nod<<1|1); else{
    	return ask(l,mid,i,mid,nod<<1)+ask(mid+1,r,mid+1,j,nod<<1|1);
	}
}
inline void build(int l,int r,int nod){
	int mid=(l+r)>>1; lazy[nod]=0;
	if (l==r){tree[nod]=a[pos[l]]; return;}
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	tree[nod]=tree[nod<<1]+tree[nod<<1|1];
}
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
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
inline int fa(int x,int y){
	return in[x]<=in[y]&&out[x]>=out[y];
}
inline int LCA(int a,int b){
	if(fa(a,b))return a; else if(fa(b,a))return b;
	int k=a;
	for(int j=20;j>=0;j--)if(dp[k][j]&&!fa(dp[k][j],b))k=dp[k][j];//cout<<a<<" "<<b<<" "<<k<<endl;
	return dp[k][0];
}
inline int query(int u,int v){
	for(int i=20;i>=0;i--)if(dp[u][i]&&!fa(dp[u][i],v))u=dp[u][i];
	return u;
}
int query(int nod){
	int ans;
	if(fa(nod,root)){
		ans=ask(1,n,1,n,1); if(nod==root)return ans;
		int tt=query(root,nod);
		ans-=ask(1,n,in[tt],out[tt],1);
	}else{
		ans=ask(1,n,in[nod],out[nod],1);
	}
	return ans;
}
void update(int nod,int x){
	if(fa(nod,root)){
		insert(1,n,1,n,x,1); if(nod==root)return;
		int tt=query(root,nod);
		insert(1,n,in[tt],out[tt],-x,1);
	}else{
		insert(1,n,in[nod],out[nod],x,1);
	}
}
inline int qiu(int a,int b){
	int t=LCA(a,b);
	return dist[a]+dist[b]-(dist[t]<<1);
}
inline int find(int a,int b,int c){
	int t=qiu(a,c)<qiu(b,c)?a:b;
	int tt=LCA(a,c);
	if(!fa(tt,b)&&qiu(tt,c)<qiu(t,c))t=tt;
	return t;
}
signed main(){
	n=read();q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		aedge(s,t); aedge(t,s);
	}
	dfs(1,0);
	build(1,n,1);
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
	while(q--){
		int op=read();
		if(op==1){
			root=read();
		}else if(op==2){
			int u=read(),v=read(),t;
			int tt=LCA(u,root);
			int t1=find(u,tt,v),t2=find(root,tt,v);
			t=qiu(t1,v)<qiu(t2,v)?t1:t2;
			update(t,read());
		}else{
			int x=read();
			writeln(query(x));
		}
	}
	//cout<<ask(1,n,1,n,1)<<endl;
}