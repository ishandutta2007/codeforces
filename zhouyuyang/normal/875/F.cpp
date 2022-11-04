#include<bits/stdc++.h>
#define N 200005
using namespace std;
int x[N],y[N],z[N],f[N],ch[N],id[N];
int n,m,ans;
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
bool cmp(int x,int y){
	return z[x]>z[y];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		f[i]=i,ch[i]=1;
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&x[i],&y[i],&z[i]),id[i]=i;
	sort(id+1,id+m+1,cmp);
	for (int i=1;i<=m;i++){
		int k=id[i],u=get(x[k]),v=get(y[k]);
		if (!ch[u]) swap(u,v);
		if (ch[u]&&ch[v]){
			if (u!=v) f[u]=v,ch[v]+=ch[u];
			ch[v]--; ans+=z[k];
		}
		else if (ch[u])
			ch[u]--,ans+=z[k];
	}
	printf("%d",ans);
}