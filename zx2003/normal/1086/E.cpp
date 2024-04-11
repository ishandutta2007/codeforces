#include<bits/stdc++.h>
const int mo=998244353,N=2005;
int n,a[N][N],ia[N][N],i,j,f[N][N],bi[N],mi[N],fac[N],ans;
inline void add(int x,int v=1){for(;x<=n;x+=x&-x)bi[x]+=v;}
inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
int main(){
	for(i=*fac=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d",&n);for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",a[i]+j);
	f[0][0]=1;
	for(i=1;i<=n;++i)for(f[i][0]=fac[i],j=1;j<=i;++j)
		f[i][j]=(1ll*f[i-1][j-1]*(i-j)+(j>1?1ll*f[i-1][j-2]*(j-1):0))%mo;
	for(i=*mi=1;i<=n;++i)mi[i]=1ll*mi[i-1]*f[n][n]%mo;
	for(i=n;i;--i)ans=(ans+1ll*fac[n-i]*ask(a[1][i]))%mo,add(a[1][i]);ans=1ll*ans*mi[n-1]%mo;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)ia[i][a[i][j]]=j;
	for(i=2;i<=n;++i){
		int tot=0;
		int cnt=0;
		memset(bi+1,0,n<<2);
		for(j=n;j;--j){
			if(ia[i-1][a[i][j]]>j)add(a[i][j]),++cnt;
			if(cnt){
				int w=ask(a[i][j]-1);
				tot=(tot+1ll*w*f[n-j][cnt-1])%mo;
			}
			if(ia[i][a[i-1][j]]>j)add(a[i-1][j]),++cnt;
		}
		cnt=0;
		memset(bi+1,0,n<<2);
		for(j=n;j;--j){
			if(ia[i][a[i-1][j]]>j)add(a[i-1][j],-1);
			int w=ask(a[i][j]-1);
			if(ia[i-1][a[i][j]]>j)++cnt;
			tot=(tot+1ll*w*f[n-j][cnt])%mo;
			if(ia[i-1][a[i][j]]<j)add(a[i][j]);
			if(ia[i][a[i-1][j]]>j)++cnt;
		}
		ans=(ans+1ll*tot*mi[n-i])%mo;
	}
	printf("%d\n",ans);
}