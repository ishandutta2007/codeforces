#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mo=1e9+7;
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
int T,n,p,k[N],i,j,x,ans,tot;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&p);
		tot=0;for(i=1;i<=n;++i)scanf("%d",k+i),tot=(tot+poww(p,k[i]))%mo;
		if(p==1){printf("%d\n",n&1);continue;}
		sort(k+1,k+n+1);
		ans=x=0;j=k[i];
		for(i=n;i;--i){
			if(!x)j=k[i];else{
				for(;j>k[i] && x<=1e6;--j,x=min(1ll*x*p,1ll<<20));
				if(x>1e6){for(;i;--i)ans=(ans+poww(p,k[i]))%mo;break;}
			}
			if(x>0)--x,ans=(ans+poww(p,k[i]))%mo;else ++x;
		}
		ans=(tot+mo-2ll*ans%mo)%mo;printf("%d\n",ans);
	}
}