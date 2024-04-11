#include <bits/stdc++.h>
using namespace std;
const int N=1<<22;
int n,m,s,a[N],f[N],v[N];
void dfs(int x){
	if (v[x])
		return;
	v[x]=1;
	if (f[x])
		dfs(s^x);
	for (int i=0;i<n;i++)
		if (x&(1<<i))
			dfs(x^(1<<i));
}
int main(){
	scanf("%d%d",&n,&m);
	s=(1<<n)-1;
	memset(f,0,sizeof f);
	memset(v,0,sizeof v);
	for (int i=1;i<=m;i++)
		scanf("%d",&a[i]),f[a[i]]=1;
	int ans=0;
	for (int i=1;i<=m;i++)
		if (!v[a[i]]){
			v[a[i]]=1;
			dfs(s^a[i]);
			ans++;
		}
	printf("%d",ans);
	return 0;
}