#include<bits/stdc++.h>
const int U=1e7,mo=1e9+7;
int n,x,i,j,a[U+5],c[U+5],mi[U/10],ans;
int p[U/10],xb,mu[U+5];
bool b[U+5];
inline void add(int&x,int y){x+=y-mo;x+=x>>31&mo;}
inline void dec(int&x,int y){x-=y;x+=x>>31&mo;}
int main(){
	mu[1]=1;
	for(i=2;i<=U;++i){
		if(!b[i])p[++xb]=i,mu[i]=-1;
		for(j=1;j<=xb;++j){
			x=i*p[j];if(x>U)break;
			b[x]=1;if(i%p[j]==0)break;mu[x]=-mu[i];
		}
	}
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",&x),++a[x];
	for(i=2,mi[1]=1;i<=n;++i)mi[i]=(mi[i-1]<<1|1)%mo;
	for(i=1;i<=xb;++i)for(j=U/p[i];j;--j)a[j]+=a[j*p[i]];
	for(i=1;i<=U;++i)c[i]=mi[a[i]];
	x=0;for(i=1;i<=U;++i)if(mu[i])(mu[i]==1?add:dec)(x,c[i]);dec(c[1],x);
	for(i=1;i<=U;++i)if(mu[i])
		ans=(ans+1ll*(mu[i]==1?a[i]:mo-a[i])*c[i])%mo;
	printf("%d\n",ans);
	return 0;
}