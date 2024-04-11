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
int n,K,sum,num,a[N],f[N];
vector<int>G[N];
void dfs(int x,int fa){
	f[x]=a[x];
	for(int y:G[x])
		if(y^fa)dfs(y,x),f[x]^=f[y];
	if(f[x]==sum)num++,f[x]=0;
}
inline void work(){
	n=read(),K=read(),sum=0;
	for(int i=1;i<=n;i++)a[i]=read(),sum^=a[i],G[i].clear();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);	
	}
	if(!sum){puts("YES");return;}
	if(K==2){puts("NO");return;}
	num=0,dfs(1,0);
	puts(num>=3?"YES":"NO");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}