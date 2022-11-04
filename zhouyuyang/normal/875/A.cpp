#include<bits/stdc++.h>
using namespace std;
int n,tot,mx;
int ans[100005],p[15],a[15],pre[15];
void dfs(int x,int v,int y){
	if (v>pre[x]||v<0) return;
	if (x==1){
		if (v%p[1]==0)
			ans[++tot]=y*10+v/p[1];
		return;
	}
	for (int i=0;i<=9;i++)
		dfs(x-1,v-p[x]*i,y*10+i);
}
int main(){
	p[1]=1; scanf("%d",&n);
	for (int i=2;i<=9;i++)
		p[i]=p[i-1]*10;
	for (int i=1;i<=9;i++)
		p[i]++,pre[i]=pre[i-1]+p[i]*9;
	dfs(9,n,0);
	printf("%d\n",tot);
	sort(ans+1,ans+tot+1);
	for (int i=1;i<=tot;i++)
		printf("%d\n",ans[i]);
}