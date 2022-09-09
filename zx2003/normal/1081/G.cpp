#include<bits/stdc++.h>
const int N=2e5+5;
int n,k,mo,ans,inv[N],i,cnt[N],mn=N;
void dfs(int l,int r,int h){
	if(l==r || h<=1){++cnt[r-l+1];mn=std::min(mn,r-l+1);return;}
	int m=l+r>>1;dfs(l,m,h-1);dfs(m+1,r,h-1);
}
inline int calc(int x,int y){
	int ans=0;
	for(i=2;i<=x+y;++i)ans=(ans+1ll*inv[i]*(std::min(i-1,x)-std::max(i-y,1)+1))%mo;
	return (1ll*x*y%mo*inv[2]+mo-ans)%mo;
}
int main(){
	scanf("%d%d%d",&n,&k,&mo);for(i=2,inv[1]=1;i<N;++i)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	dfs(1,n,k);
	ans=(1ll*mn*(mn-1)%mo*cnt[mn]+1ll*(mn+1)*mn%mo*cnt[mn+1])%mo*inv[4]%mo;
	ans=(ans+1ll*cnt[mn]*(cnt[mn]-1)/2%mo*calc(mn,mn))%mo;
	ans=(ans+1ll*cnt[mn+1]*(cnt[mn+1]-1)/2%mo*calc(mn+1,mn+1))%mo;
	ans=(ans+1ll*cnt[mn]*cnt[mn+1]%mo*calc(mn,mn+1))%mo;
	printf("%d\n",ans);
	return 0;
}