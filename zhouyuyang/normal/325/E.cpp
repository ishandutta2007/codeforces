#include<bits/stdc++.h>
using namespace std;
int n,vis[100005],a[100005];
void dfs(int x){
	vis[x]=1;
	if (!vis[2*x%n]) dfs(2*x%n);
	if (!vis[2*x%n+1]) dfs(2*x%n+1);
	a[++*a]=x;
}
int main(){
	scanf("%d",&n);
	if (n&1) return puts("-1"),0;
	dfs(0); a[0]=0;
	for (int i=n;i>=0;i--)
		printf("%d ",a[i]);
}