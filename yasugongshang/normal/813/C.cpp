#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;
const int N=400005;
int vis[N],sky[N],son[N],father[N],nextt[N],ed[N],nedge,ne,i,l,n,deep[N],x,ans;
inline int getfather(int x){
	if(x==father[x]) return x; else return father[x]=getfather(father[x]);
}
inline void hebing(int a,int b){
	father[getfather(a)]=getfather(b);
}
inline void aedge(int a,int b){
	nextt[++nedge]=son[a];
	son[a]=nedge;
	ed[nedge]=b;
}
inline int	read()// 
{
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
	write(a); puts("");
}
inline void dfs(int p,int fa){
	for(int i=son[p];i;i=nextt[i])if(ed[i]!=fa){//cout<<p<<" "<<ed[i]<<endl;
		deep[ed[i]]=deep[p]+1; dfs(ed[i],p); 
		hebing(p,ed[i]);
		sky[getfather(ed[i])]=p;
	}
	vis[p]=true;
	if(p==x){
		//cout<<nextt[son[3]]<<" "<<vis[3]<<" "<<deep[sky[getfather(3)]]<<" "<<deep[3]<<" "<<deep[p]<<endl;
		for(int i=2;i<=n;i++)if(nextt[son[i]]==0&&vis[i]){
			if(-2*deep[sky[getfather(i)]]+deep[i]+deep[p]<deep[i])ans=max(ans,deep[i]*2);
		}
	}else{
		if(nextt[son[p]]==0&&p!=1&&vis[x]&&-2*deep[sky[getfather(x)]]+deep[x]+deep[p]<deep[p])ans=max(ans,deep[p]*2 );
	}
}
int main(){
	n=read(); x=read();
	for(i=1;i<=n;i++){
		father[i]=i; son[i]=0; vis[i]=0; 
	}
	for(i=1;i<=n-1;i++){
		int a=read(),b=read();
		aedge(a,b); aedge(b,a);
	}
	dfs(1,0); ans=max(ans,2*deep[x]);
	writeln(ans);
}