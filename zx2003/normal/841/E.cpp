#include<cstdio>
#include<algorithm>
typedef long long ll;
const int mo=1000000007,N=305;
int n,f[N][N],i,j,k,a[N],w,c[N],d[N],l,fac[N],s[N],p,x,C[N][N],split[N][N],ans;
bool b[N];
inline bool isps(ll x){
	ll l=1,r=mo-7,m;
	while(l<r){
		m=(l+r)>>1;
		if(m*m<x)l=m+1;
			else r=m;
	}
	return l*l==x;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)if(!b[i]){
		for(j=i+1,w=0;j<=n;++j)if(isps(1ll*a[i]*a[j]))c[++w]=j;
		for(j=1;j<=w;++j)b[c[j]]=1;
		d[++l]=++w;
	}
	for(i=*fac=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mo;
	for(i=**C=1;i<=n;++i)
		for(j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	split[1][1]=1;
	for(i=2;i<=n;++i)
		for(j=2,split[i][1]=1;j<=i;++j)
			for(k=1;k<=i-j+1;++k)split[i][j]=(split[i][j]+split[i-k][j-1])%mo;
	std::sort(d+1,d+l+1,cmp);
	for(i=1;i<=l;++i)s[i]=s[i-1]+d[i];
	f[1][d[1]-1]=1;
	for(i=2;i<=l;++i)//i 
		for(j=0;j<=s[i]-i;++j){//j"bad neighbor" 
			int&x=f[i][j];
			for(k=1;k<=d[i];++k)//ik 
				for(p=0;p<=k;++p)//p "bad neighbor"  
					if(j+p+k>=d[i] && s[i-1]+1>=j+p-(d[i]-k))
						x=(x+1ll*f[i-1][j+p-(d[i]-k)]*split[d[i]][k]%mo*
						C[j+p-(d[i]-k)][p]%mo*C[s[i-1]+1-j-p+(d[i]-k)][k-p]%mo)%mo;
			//printf("f[%d][%d]=%d\n",i,j,x);
		}
	for(i=1,ans=*f[l];i<=l;++i)ans=1ll*ans*fac[d[i]]%mo;
	printf("%d\n",ans);
	return 0;
}