#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10;
struct node{
	int x,k,l,r,ans,id;
}q[M];
int n,m,tot,cnt,size;
int head[M],nxt[M<<1],to[M<<1];
int w[M],num[M],COUNT[M],be[M],L[M],R[M],dfn[M],wt[M];
bool cmp(node x,node y){
	return be[x.l]==be[y.l]?x.r<y.r:be[x.l]<be[y.l];
}
bool cmpp(node x,node y){
	return x.id<y.id;
}
void add(int x,int y){
	nxt[++cnt]=head[x]; to[cnt]=y; head[x]=cnt;
	nxt[++cnt]=head[y]; to[cnt]=x; head[y]=cnt;
}
void dfs(int x,int fa){
	L[x]=++tot; wt[tot]=w[x];
	for (int i=head[x];i;i=nxt[i])
		if (to[i]!=fa) dfs(to[i],x);
	R[x]=tot;
}
void D(int p){
	num[COUNT[wt[p]]--]--;
}
void A(int p){
	num[++COUNT[wt[p]]]++;
}
void solve(){
	int l=1,r=0;
	for (int i=1;i<=m;i++){
		while (l<q[i].l) D(l++);
		while (l>q[i].l) A(--l);
		while (r<q[i].r) A(++r);
		while (r>q[i].r) D(r--);
		q[i].ans=num[q[i].k];
	}
}
int main(){
	n=read(); m=read();
	size=sqrt(n);
	for (int i=1;i<=n;i++){
		w[i]=read();
		be[i]=i/size;
	}
	for (int i=1;i<n;i++){
		add(read(),read());
	}
	dfs(1,0);
	for (int i=1;i<=m;i++){
		int x=read();
		q[i]=(node){x,read(),L[x],R[x],0,i};
	}
	sort(q+1,q+m+1,cmp);
	solve();
	sort(q+1,q+m+1,cmpp);
	for (int i=1;i<=m;i++){
		cout<<q[i].ans<<"\n";
	}
	return 0;
}