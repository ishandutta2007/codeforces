#include<bits/stdc++.h>
const int N=1e6+5,mo=1e9+7;
char c[N];
int n,a[N],m,i,zz,fa[N],f[N],g[N],st[N],w,ans;
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	for(i=1;i<=n;++i)if(c[i]=='1')a[++m]=zz,zz=0;else ++zz;
	for(i=m;i;--i){
		for(;w && a[i]>=a[st[w]];--w);
		fa[i]=st[w];st[++w]=i;
	}
	f[0]=1;
	for(i=0;i<m;++i){
		f[i+1]=(f[i+1]+1ll*(a[i+1]+1)*f[i])%mo;
		if(i)g[i+1]=(g[i+1]+f[i])%mo;
		if(fa[i])g[fa[i]]=(g[fa[i]]+g[i])%mo,f[fa[i]]=(f[fa[i]]+1ll*(a[fa[i]]-a[i])*g[i])%mo;
	}
	for(i=1;i<=m;++i)ans=(ans+f[i])%mo;
	ans=1ll*ans*(zz+1)%mo;if(m==0)ans=n;printf("%d\n",ans);
}