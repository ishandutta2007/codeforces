#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
struct seg{int l,r;}a[N];
struct Edge{int to,nxt;}e[N<<2];
int s_e=1,head[N<<1],deg[N<<1];
inline void add_e(int x,int y){
	e[++s_e]={y,head[x]},head[x]=s_e,deg[x]^=1;
}
int n,m,lsh[N<<1],ans[N<<1];
bool vis[N<<1];
void find(int x){
	while(head[x]){
		int i=head[x];head[x]=e[i].nxt;
		if(!vis[i>>1])vis[i>>1]=1,find(e[i].to),ans[i>>1]=x<e[i].to?0:1;
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++)a[i].l=lsh[++m]=read()<<1,a[i].r=lsh[++m]=(read()<<1)+1;
	sort(lsh+1,lsh+m+1),m=unique(lsh+1,lsh+m+1)-lsh-1;
	for(int i=1;i<=n;i++){
		int x=lower_bound(lsh+1,lsh+m+1,a[i].l)-lsh;
		int y=lower_bound(lsh+1,lsh+m+1,a[i].r)-lsh;
		add_e(x,y),add_e(y,x);
	}
	vector<int>vec;
	for(int i=1;i<=m;i++)if(deg[i])vec.push_back(i);
	for(int i=0;i<(int)vec.size();i+=2)add_e(vec[i],vec[i+1]),add_e(vec[i+1],vec[i]);
	for(int i=1;i<=m;i++)if(head[i])find(i);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}