#include<bits/stdc++.h>
const int N=2025,mo=998244353;
int n,k;
namespace S1{
int cnt=0,xb,a[N];
inline bool ck(){
	static int buc[N],nbuc[N];
	int mx=a[xb],i;
	memset(buc+1,0,mx<<2);
	for(i=1;i<=xb;++i)++buc[a[i]];
	int tt=k-1;
	for(;tt--;){
		int zz=0,su=0;
		for(i=1;i<=mx;++i)su+=buc[i]*i;if(su>n)return 0;
		for(i=mx;i;--i)for(;buc[i]--;)nbuc[++zz]=i;
		mx=zz;memcpy(buc+1,nbuc+1,zz<<2);
	}
	int su=0;for(i=1;i<=mx;++i)su+=buc[i]*i;if(su>n)return 0;
	return 1;
}
void dfs(int lst){
	++cnt;
	for(int i=lst;i<=n;++i){
		a[++xb]=i;if(ck())dfs(i);else{--xb;return;}--xb;
	}
}
}
namespace S2{
int a[N],xb,i,j,f[N];
inline void add(int&a,const int&b){a+=b-mo;a+=a>>31&mo;}
inline void solve(){
	if(k==1)for(i=1;i<=n;++i)a[++xb]=i;else for(i=1;i*(i+1)/2<=n;++i)a[++xb]=i*(i+1)/2;
	f[0]=1;
	for(i=1;i<=xb;++i)for(j=a[i];j<=n;++j)add(f[j],f[j-a[i]]);
	int ans=0;for(i=1;i<=n;++i)add(ans,f[i]);
	printf("%d\n",ans);
}
}
int main(){
	scanf("%d%d",&n,&k);
	if(k>2)S1::dfs(1),printf("%d\n",S1::cnt-1);
		else S2::solve();
	return 0;
}