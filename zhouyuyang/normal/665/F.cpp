#include<bits/stdc++.h>
#define ll long long
#define N 22000000
using namespace std;
int cnt[N],pri[N/12],tot;
int f[105][300005];
bool fl[N];
void init(){
	fl[1]=1; cnt[1]=0;
	for (int i=2;i<N;i++){
		cnt[i]=cnt[i-1];
		if (!fl[i]){
			pri[++tot]=i;
			cnt[i]++;
		}	
		for (int j=1;i*pri[j]<N&&j<=tot;j++){
			fl[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	for (int i=1;i<=300000;i++)
		f[0][i]=i;
	for (int i=1;i<105;i++)
		for (int j=1;j<=300000;j++)
			f[i][j]=f[i-1][j]-f[i-1][j/pri[i]];
}
map<ll,ll> mp;
int times=0;
ll dp(ll x,int y){
	if (x<=300000&&y<=103) return f[y][x];
	if (1ll*pri[y]*pri[y]>=x) return max(0,cnt[x]-y+1);
	if (!y) return x;
	ll hsh=x*1000+y;
	if (mp.find(hsh)!=mp.end()) return mp[hsh];
	return mp[hsh]=dp(x,y-1)-dp(x/pri[y],y-1);
}
ll calcpri(ll lim){
	if (lim<N) return (ll)cnt[lim];
	ll tmp=1;
	for (;1ll*pri[tmp]*pri[tmp]*pri[tmp]<=lim;tmp++);
	tmp--;
	ll ans=dp(lim,tmp)+tmp-1;
	for (int id=tmp+1;1ll*pri[id]*pri[id]<=lim;id++)
		ans-=cnt[lim/pri[id]]-id+1;
	return ans; 
}
ll n;
int main(){
	init();
	scanf("%I64d",&n);
	ll ans=0;
	for (int i=1;1ll*pri[i]*pri[i]*pri[i]<=n;i++) ans++;
	for (int i=1;1ll*pri[i]*pri[i]<=n;i++)
		ans+=calcpri(n/pri[i])-i;
	printf("%lld",ans);
}