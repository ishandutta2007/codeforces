#include <bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define DF(i,a,b) for(int i=a;i>=b;--i)
#define LL long long
using namespace std;
const int M=4e5+10;
char ch[M];
int n,tot=1,last=1,pos[M];
struct node{
	int len,fa;
	int ch[30];
}t[M];
int nxt[M<<1],to[M<<1],cnt,head[M];
void add(int x,int y){
	nxt[++cnt]=head[x]; to[cnt]=y; head[x]=cnt;
} 
#define mid (l+r>>1)
int s[M<<6],yjy,L[M<<6],R[M<<6];
int rt[M];
void ins(int &x,int l,int r,int p){
	if (!x) x=++yjy;
	if (l==r) {
		s[x]++;
		return ;
	}
	if (p<=mid) ins(L[x],l,mid,p);
	else ins(R[x],mid+1,r,p);
	s[x]=s[L[x]]+s[R[x]];
}
int merge(int x,int y){
	if (!x || !y) return x|y;
	int nw=++yjy;
	L[nw]=merge(L[x],L[y]); 
	R[nw]=merge(R[x],R[y]);
	s[nw]=s[L[nw]]+s[R[nw]];
	return nw;
}
int qry(int x,int l,int r,int ll,int rr){
	if (l==ll && r==rr) return s[x];
	if (ll>mid) return qry(R[x],mid+1,r,ll,rr);
	if (rr<=mid) return qry(L[x],l,mid,ll,rr);
	return qry(L[x],l,mid,ll,mid)+qry(R[x],mid+1,r,mid+1,rr);
}
void extend(int c,int id){
	int np=++tot,p=last; last=np; t[np].len=t[p].len+1;
	while (p&&!t[p].ch[c]) t[p].ch[c]=np,p=t[p].fa; ins(rt[np],1,n,id); pos[np]=id;
//	cout<<np<<" "<<id<<"\n";
	if (!p) t[np].fa=1;
	else {
		int q=t[p].ch[c];
		if (t[p].len+1==t[q].len) t[np].fa=q;
		else {
			int nq=++tot; t[nq]=t[q]; t[nq].len=t[p].len+1;
			t[np].fa=t[q].fa=nq;
			while (p&&t[p].ch[c]==q) t[p].ch[c]=nq,p=t[p].fa;
		}
	}
}
int f[M],ans;
void dfs1(int x){
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		dfs1(y);
		pos[x]=max(pos[x],pos[y]);
		rt[x]=merge(rt[x],rt[y]);
	}
}
int tp[M];
void dfs(int x){
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (x==1) {	
			f[y]=1; tp[y]=y;
			dfs(y);
			continue;
		}	
//		cout<<x<<" "<<y<<"\n";
//		cout<<pos[y]-t[y].len+t[x].len<<" ~ "<<pos[y]<<"\n";
//		cout<<qry(rt[x],1,n,pos[y]-t[y].len+t[x].len,pos[y])<<"   fuck\n";
		if (qry(rt[tp[x]],1,n,pos[y]-t[y].len+t[tp[x]].len,pos[y])>=2) tp[y]=y,f[y]=f[x]+1;
		else tp[y]=tp[x],f[y]=f[x];
		dfs(y);
	}
	ans=max(ans,f[x]);
}
int main(){
	scanf("%d%s",&n,ch+1);
	F(i,1,n) {
		extend(ch[i]-'a',i);
	}
	F(i,2,tot) add(t[i].fa,i);
	dfs1(1); tp[1]=1; dfs(1);
//	cout<<qry(rt[4],1,n,3,10)<<"\n";
	cout<<ans<<"\n";
	return 0;
}