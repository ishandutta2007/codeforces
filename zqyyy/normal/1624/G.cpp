#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int pa[N];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
int n,m,u[N],v[N],w[N];
inline bool ck(int k){
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1;i<=m;i++)if((w[i]&k)==w[i])pa[find(u[i])]=find(v[i]);
	int tot=0;
	for(int i=1;i<=n;i++)tot+=find(i)==i;
	return tot==1;
}
inline void work(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)u[i]=read(),v[i]=read(),w[i]=read();
	int ans=(1<<30)-1;
	for(int i=29;~i;i--)if(ck(ans^(1<<i)))ans^=1<<i;
	printf("%d\n",ans);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}