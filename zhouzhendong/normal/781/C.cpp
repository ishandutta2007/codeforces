#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=400005;
int n,m,k;
vector <int> e[N];
int vis[N];
int dfn[N],b[N],t=0;
void dfs(int x){
	dfn[++t]=x;
	vis[x]=1;
	for (auto y : e[x])
		if (!vis[y]){
			dfs(y);
			dfn[++t]=x;
		}
}
int main(){
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++){
		int a=read(),b=read();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(vis,0,sizeof vis);
	dfs(1);
	int s=(2*n+k-1)/k;
	memset(b,0,sizeof b);
	b[t]=1;
	for (int i=1;i<k;i++)
		b[i]=1;
	for (int i=k-1,last=t;i>=1;i--){
		if (last-i>s)
			swap(b[i],b[last-s]),last=last-s;
		else
			last=i;
	}
	for (int last=1,i=1;i<=t;i++)
		if (b[i]){
			printf("%d ",i-last+1);
			for (int j=last;j<=i;j++)
				printf("%d ",dfn[j]);
			puts("");
			last=i+1;
		}
	return 0;
}