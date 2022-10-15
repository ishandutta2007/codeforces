#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7,inf=1e9;
int n,d[N],dep[N];
vector<int>G[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)G[i].clear(),d[i]=0,dep[i]=1;
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--)G[read()].push_back(i),d[i]++;	
	}
	queue<int>q;
	for(int i=1;i<=n;i++)if(!d[i])q.push(i);
	while(!q.empty()){//
		int x=q.front();q.pop();
		for(int y:G[x]){
			dep[y]=max(dep[y],dep[x]+(x>y));
			if(!--d[y])q.push(y);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(d[i])ans=inf;
		else ans=max(ans,dep[i]);
	printf("%d\n",ans==inf?-1:ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}