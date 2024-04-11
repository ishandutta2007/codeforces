#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7,M=3e5+7;
struct edge{int x,y,w,id;}e[M];
int pa[N],sz[N];
int find(int x){return pa[x]^x?find(pa[x]):x;}
int cnt,tp;
struct node{int x,y,v;};
node stk[N];
inline void unin(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(sz[x]>sz[y])swap(x,y);
	stk[++tp]={x,y,0};
	if((sz[x]&1) && (sz[y]&1))cnt-=2,stk[tp].v=2;
	sz[y]+=sz[x],pa[x]=y;
}
inline void undo(){
	int x=stk[tp].x,y=stk[tp].y;
	cnt+=stk[tp--].v,pa[x]=x,sz[y]-=sz[x];
}
int n,m,now,ans[M];
#define ls (p<<1)
#define rs (p<<1|1)
vector<int>vec[M<<2];
void modify(int p,int l,int r,int x,int y,int i){
	if(x<=l && r<=y)return vec[p].push_back(i);int mid=(l+r)>>1;
	if(x<=mid)modify(ls,l,mid,x,y,i);if(y>mid)modify(rs,mid+1,r,x,y,i);
}
void dfs(int p,int l,int r){
	int lst=tp;
	for(int i:vec[p])unin(e[i].x,e[i].y);
	if(l==r){
		while(cnt && now<m){
			now++;
			if(e[now].id<=l){
				unin(e[now].x,e[now].y);
				if(e[now].id<l)modify(1,1,m,e[now].id,l-1,now);
			}
		}
		ans[l]=cnt?-1:e[now].w;
	}else{
		int mid=(l+r)>>1;
		dfs(rs,mid+1,r),dfs(ls,l,mid);
	}
	while(tp>lst)undo();
}
#undef ls
#undef rs
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read();
	if(n&1){while(m--)puts("-1");exit(0);}
	for(int i=1;i<=m;i++)e[i].x=read(),e[i].y=read(),e[i].w=read(),e[i].id=i;
	sort(e+1,e+m+1,[&](auto x,auto y){return x.w<y.w;});
	for(int i=1;i<=n;i++)pa[i]=i,sz[i]=1;
	cnt=n,dfs(1,1,m);
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}