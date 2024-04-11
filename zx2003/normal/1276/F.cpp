#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
char c[N];int n,i;ll ans=2;
struct SAM{
int ch[N*2][26],step[N*2],pre[N*2],xb,pos[N];
vector<int>e[N*2];
void build(){
	int lst=xb=1,p,q,np,nq,i,j,x;
	for(i=1;i<=n;++i){
		x=c[i]-'a';step[np=++xb]=step[p=lst]+1;
		for(;p && !ch[p][x];p=pre[p])ch[p][x]=np;
		if(p){
			q=ch[p][x];
			if(step[p]+1!=step[q]){
				step[nq=++xb]=step[p]+1;memcpy(ch[nq],ch[q],104);
				pre[nq]=pre[q];pre[q]=pre[np]=nq;
				for(;p && ch[p][x]==q;p=pre[p])ch[p][x]=nq;
			}else pre[np]=q;
		}else pre[np]=1;pos[i]=lst=np;
		if(i==n-1)for(j=2;j<=xb;++j)ans+=step[j]-step[pre[j]];
	}
	for(i=2;i<=xb;++i)e[pre[i]].push_back(i);
}
};
int lo[N*4];
struct SAM2:SAM{
int f[20][N*4],dcnt,id[N*2];
void dfs(int x){f[0][id[x]=++dcnt]=step[x];for(int y:e[x])dfs(y),f[0][++dcnt]=step[x];}
void initlca(){
	dfs(1);
	for(int i=1;i<20;++i)for(int j=1;j+(1<<i)-1<=dcnt;++j)f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
}
inline int ask(int x,int y){int l=lo[y-x+1];return min(f[l][x],f[l][y-(1<<l)+1]);}
}B;
struct node{int l,r,mn,mx;ll s;}t[N*22];int tcnt;
void upd(int i){
	int L=t[i].l,R=t[i].r;
	t[i].s=t[L].s+t[R].s-(L && R?B.ask(t[L].mx,t[R].mn):0);
	t[i].mx=R?t[R].mx:t[L].mx;t[i].mn=L?t[L].mn:t[R].mn;
}
void ins(int&x,int l,int r,int k){
	if(!x)x=++tcnt;if(l==r){t[x].mn=t[x].mx=k;t[x].s=B.f[0][k];return;}
	int m=l+r>>1;if(k<=m)ins(t[x].l,l,m,k);else ins(t[x].r,m+1,r,k);upd(x);
}
int merge(int x,int y,int l,int r){
	if(!x || !y)return x|y;if(l==r)return x;
	int m=l+r>>1;t[x].l=merge(t[x].l,t[y].l,l,m);t[x].r=merge(t[x].r,t[y].r,m+1,r);upd(x);return x;
}
struct SAM1:SAM{
int rt[N*2];
void dfs(int x){
	for(int y:e[x])dfs(y),rt[x]=merge(rt[x],rt[y],1,B.dcnt);
	ans+=(step[x]-step[pre[x]])*t[rt[x]].s;
}
}A;
int main(){
	for(i=2;i<N*4;++i)lo[i]=lo[i>>1]+1;
	scanf("%s",c+1);n=strlen(c+1);
	A.build();reverse(c+1,c+n+1);B.build();
	B.initlca();
	for(i=2;i<=A.xb;++i)ans+=A.step[i]-A.step[A.pre[i]];
	for(i=1;i+2<=n;++i)ins(A.rt[A.pos[i]],1,B.dcnt,B.id[B.pos[n-i-1]]);
	A.dfs(1);cout<<ans<<endl;
	return 0;
}