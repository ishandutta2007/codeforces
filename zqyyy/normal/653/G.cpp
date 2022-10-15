#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e6+7,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int fac[N],ifac[N];
inline int C(int n,int m){
	if(m<0 || n<m)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int n,m,a[N],s[N];
int s_p,pr[N],v[N];
vector<int>f[N],cnt[N];
inline void init(){
	for(int i=2;i<=m;i++){
		if(!v[i])v[i]=i,pr[++s_p]=i;
		for(int j=1;j<=s_p && i*pr[j]<=m;j++){
			v[i*pr[j]]=pr[j];
			if(i%pr[j]==0)break;
		}
	}
	for(int j=1;j<=s_p;j++)
		for(int i=pr[j];i<=m;i+=pr[j])
			f[i].push_back(j);
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),m=max(m,a[i]);
	init();
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j:f[a[i]]){
			int num=0;
			while(x%pr[j]==0)num++,x/=pr[j];
			cnt[j].push_back(num);
		}
	}
	s[0]=1;
	for(int i=1;i<=n;i++)s[i]=(s[i-1]+C(n-1,i))%mod;
	int ans=0;
	for(int i=1;i<=s_p;i++)sort(cnt[i].begin(),cnt[i].end(),greater<int>());
	for(int i=1;i<=s_p;i++)
		for(int j=0;j<(int)cnt[i].size();j++){
			int res=0;
			if(n-j-2>=0)res=s[n-j-2];
			if(j)res=(res+mod-s[j-1]);
			ans=(ans+1ll*res*cnt[i][j])%mod;
		}
	printf("%d\n",ans);
	return 0;
}