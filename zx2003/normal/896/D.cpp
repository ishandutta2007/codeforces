#include<cstdio>
#include<cstring>
const int N=100005;
int n,l,r,p,i,a[12],xb,x,y,s[N][12],j,jf[N],vf[N],rl,rr,ans;
inline int pow(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%p)if(y&1)ans=1ll*ans*x%p;
	return ans;
}
inline int C(int x,int y){
	int i,ans=1ll*jf[x]*vf[y]%p*vf[x-y]%p;
	for(i=1;i<=xb;++i)
		ans=1ll*ans*pow(a[i],s[x][i]-s[y][i]-s[x-y][i])%p;
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&p,&l,&r);
	for(i=2,x=y=p;i*i<=x;++i)
		if(x%i==0){
			a[++xb]=i;y=y/i*(i-1);
			while(x%i==0)x/=i;
		}
	if(x>1)a[++xb]=x,y=y/x*(x-1);
	*jf=*vf=1;
	for(i=1;i<=n;++i){
		for(x=i,memcpy(s[i],s[i-1],48),j=1;j<=xb;++j)
			if(x%a[j]==0)
				while(x%a[j]==0)x/=a[j],++s[i][j];
		jf[i]=1ll*jf[i-1]*x%p;
		vf[i]=1ll*vf[i-1]*pow(x,y-1)%p;
	}
	for(i=0;i<=n-l;++i){
		j=n-i;
		rl=(j+l+1)>>1;
		rr=(j+r)>>1;
		if(rl>rr)continue;
		if(rl>j)rl=j;
		if(rr>j)rr=j;
		if(rl<<1<j)rl=(j+1)>>1;
		if(rl<=rr){
			x=j-rr;
			y=j-rl;
			if(x>=0 && y>=0 && y<<1<=j)
				ans=(ans+1ll*C(n,i)*(1ll*C(j,y)-(x?C(j,x-1):0)+p))%p;
		}
	}
	return printf("%d\n",ans),0;
}