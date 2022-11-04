#include<bits/stdc++.h>
#define mo 1000000007
#define N 1000005
using namespace std;
int a[N],cntb[N],cnt[N];
int wh1[N],wh2[N],fac[N];
vector<int> divi[N];
int n,base[N];
bool fl[N];
void GG(){
	puts("0");
	exit(0);
}
int main(){
	scanf("%d",&n);
	cnt[1]=fac[0]=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		fac[i]=1ll*fac[i-1]*i%mo;
		base[i]=1;
	}
	divi[1].push_back(1);
	for (int i=2;i<=n;i++)
		if (!fl[i]){
			cnt[n/i]++;
			for (int j=i;j<=n;j+=i){
				fl[j]=1;
				divi[j].push_back(i);
				base[j]*=i;
			}
		}
	for (int i=1;i<=n;i++)
		cntb[base[i]]++;
	for (int i=1;i<=n;i++){
		if (!a[i]) continue;
		if (divi[i].size()!=divi[a[i]].size()) GG;
		for (int j=0;j<divi[i].size();j++){
			int u=divi[i][j],v=divi[a[i]][j];
			int pu=(u==1?1:n/u),pv=(v==1?1:n/v);
			if (pu!=pv) GG();
			if (wh1[u]&&wh1[u]!=v) GG();
			if (wh2[v]&&wh2[v]!=u) GG();
			if (wh2[v]!=u) wh2[v]=u,wh1[u]=v,cnt[pv]--;
		}
		cntb[base[i]]--;
	}
	int ans=1;
	for (int i=1;i<=n;i++)
		ans=1ll*ans*fac[cnt[i]]%mo*fac[cntb[i]]%mo;
	printf("%d",ans);
}