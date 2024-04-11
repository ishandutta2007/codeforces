#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=5005;
int n,m,s,tot,sum,tp,c[N],dfn[N],low[N],stk[N];
bool ins[N],rd[N];
vector<int>G[N];
void tarjan(int x){
	dfn[x]=low[x]=++tot,ins[x]=1,stk[++tp]=x;
	for(auto y:G[x]){
		if(!dfn[y])tarjan(y),low[x]=min(low[x],low[y]);
		else if(ins[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		sum++;int y;
		do{
			y=stk[tp--];ins[y]=0,c[y]=sum;
		}while(x^y);
	}
}
int main(){
	n=read(),m=read(),s=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		G[x].push_back(y);	
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	for(int x=1;x<=n;x++)
		for(auto y:G[x])
			if(c[x]^c[y])rd[c[y]]=1;
	int ans=0; 
	for(int i=1;i<=sum;i++)
		if(!rd[i] && c[s]!=i)ans++;
	return cout<<ans,0;
}