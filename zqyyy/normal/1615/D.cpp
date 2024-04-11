#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int pa[N<<1];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
inline void unin(int x,int y){
	x=find(x),y=find(y);
	if(x^y)pa[y]=x;
}
struct Edge{int fr,to,nxt,w;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
	e[++s_e]={x,y,head[x],w},head[x]=s_e;	
}
int n,m,ans[N],a[N];
bool ok;
void dfs(int x,int fa){
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa)continue;
		if(!~e[i].w)ans[i>>1]=a[x]^a[y];
		dfs(y,x);	
	}
}
inline void work(){
	n=read(),m=read(),s_e=1;
	for(int i=1;i<=n;i++)head[i]=0;
	iota(pa+1,pa+n+n+1,1);
	ok=1;
	for(int i=1;i<n;i++){
		int x=read(),y=read(),w=read();
		add_e(x,y,w),add_e(y,x,w),ans[i]=w;
		if(x>y)swap(x,y);
		if(!ok)continue;
		if(~w){
			if(__builtin_parity(w)){
				if(find(x)==find(y) || find(x+n)==find(y+n)){ok=0;continue;}
				unin(x,y+n),unin(x+n,y);
			}else{
				if(find(x)==find(y+n) || find(y)==find(x+n)){ok=0;continue;}
				unin(x,y),unin(x+n,y+n);	
			}
		}
	}
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),w=read();
		if(x>y)swap(x,y);
		if(!ok)continue;
		if(w==1){
			if(find(x)==find(y) || find(x+n)==find(y+n)){ok=0;continue;}
			unin(x,y+n),unin(x+n,y);
		}else{
			if(find(x)==find(y+n) || find(y)==find(x+n)){ok=0;continue;}
			unin(x,y),unin(x+n,y+n);	
		}
	}
	if(!ok){puts("NO");return;}
	for(int i=1;i<=n;i++)
		if(find(i)==i)a[i]=0;
	for(int i=1;i<=n;i++){
		int x=find(i);
		if(x==i)continue;
		if(x>n)a[i]=1-a[x-n];
		else a[i]=a[x];	
	}
	dfs(1,0);
	if(!ok){puts("NO");return;}
	puts("YES");
	for(int i=1;i<n;i++)printf("%d %d %d\n",e[i<<1].fr,e[i<<1].to,ans[i]);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}