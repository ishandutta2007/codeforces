#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e4+5;
struct Edge{
	int to,nxt;
}e[N<<1];
int cnt=1,head[N];
inline void add_e(int from,int to){
	e[++cnt].to=to;
	e[cnt].nxt=head[from];
	head[from]=cnt;
}
int n,m,tot,lst,pre[N],col[N],odd[N],even[N],dep[N];
bool ans[N];
void dfs(int x,int fa){
	col[x]=col[fa]^1,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(!(~col[y])){
			pre[y]=i>>1,dfs(y,x);
			even[x]+=even[y],odd[x]+=odd[y];
		}else if(dep[y]+1<dep[x]){
			if(col[y]==col[x])lst=i>>1,tot++,odd[x]++,odd[y]--;
			else even[x]++,even[y]--;
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add_e(x,y),add_e(y,x);
	}
	for(int i=1;i<=n;i++)col[i]=-1;
	for(int i=1;i<=n;i++)if(!(~col[i]))dfs(i,0);
	if(!tot){
		printf("%d\n",m);
		for(int i=1;i<=m;i++)printf("%d ",i);
		return 0;
	}
	int res=0;
	if(tot==1)ans[lst]=1,res++;
	for(int i=1;i<=n;i++)
		if(odd[i]==tot && !even[i])ans[pre[i]]=1,res++;
	printf("%d\n",res);
	for(int i=1;i<=m;i++)
		if(ans[i])
			printf("%d ",i);
	return 0;
}