#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=4e5+7;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,K,deg[N],d[N];
vector<int>G[N];
inline void work(){
	n=read(),K=read();
	for(int i=1;i<=n;i++)deg[i]=0,G[i].clear();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);
		deg[x]++,deg[y]++;
	}
	int ans=0;queue<int>q;
	for(int i=1;i<=n;i++)
		if(deg[i]==1)d[i]=1,q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop(),ans+=d[x]>K;
		for(int y:G[x])if(--deg[y]==1)d[y]=d[x]+1,q.push(y);	
	}
	printf("%d\n",ans);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}