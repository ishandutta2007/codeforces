#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e6+5;
int n,a[N],g[N];
bool vis[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=i-read(),g[i]=a[i],vis[i]=0;
	int x=1;
	while(!vis[x])vis[x]=1,x=g[x];
	vector<int>ans={x};x=g[x];
	while(x^ans[0])ans.push_back(x),x=g[x];
	printf("%u\n",ans.size());
	for(auto y:ans)printf("%d ",y);puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}