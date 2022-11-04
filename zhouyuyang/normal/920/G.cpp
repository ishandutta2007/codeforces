#include<bits/stdc++.h>
using namespace std;
int pri[10];
int ans;
void getfact(int x,int *pri){
	pri[0]=0;
	for (int i=2;i*i<=x;i++)
		if (x%i==0){
			pri[++pri[0]]=i;
			for (;x%i==0;x/=i);
		}
	if (x!=1)
		pri[++pri[0]]=x;
}
void dfs(int x,int dep,int times){
	if (dep>pri[0]){
		if (times&1) ans-=x;
		else ans+=x;
		return;
	}
	dfs(x,dep+1,times);
	dfs(x/pri[dep],dep+1,times+1);
}
int calc(int x){
	ans=0;
	dfs(x,1,0);
	return ans;
}
void solve(){
	int x,p,k;
	scanf("%d%d%d",&x,&p,&k);
	getfact(p,pri);
	int tmp=calc(x)+k;
	int l=x,r=1e8;
	int ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (calc(mid)>=tmp)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}