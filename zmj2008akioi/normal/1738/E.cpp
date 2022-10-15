#include <cstdio>
#include <map>
typedef long long LL;
const int N=1e5+10,P=998244353;
int T,n,top,a[N],cl[N],cr[N],dp[N],prd[N],ipr[N];
std::map<LL,int> map;
int C(int n,int m){return (LL)prd[n]*ipr[m]%P*ipr[n-m]%P;}
template<typename T>T min(T x,T y){return x<y?x:y;}
int qpow(int b,int p){
	int pw=1,rs=1,nw=b,rm=p;
	for(;rm;pw<<=1,nw=(LL)nw*nw%P)if(rm&pw)rm^=pw,rs=(LL)rs*nw%P;
	return rs;
}
int main(){
	scanf("%d",&T),prd[0]=1;const int m=1e5;
	for(int i=1;i<=m;++i)prd[i]=(LL)prd[i-1]*i%P;
	ipr[m]=qpow(prd[m],P-2);for(int i=m-1;~i;--i)ipr[i]=(LL)ipr[i+1]*(i+1)%P;
	while(T--){
		scanf("%d",&n),top=0;LL s=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),s+=a[i];
		LL ns=0,nsl=a[1],nsr=a[n];map.clear();int cnt=0;
		for(int i=1;i<n;++i)cnt+=((ns+=a[i])<<1)==s;
		for(int i=n;(nsr<<1)<s;--i)++map[nsr],nsr+=a[i-1];
		for(int i=1,g=0;;++i){
			if((nsl<<1)>=s){
				nsl-=a[i];if(map.find(nsl)==map.end())break;
				++top,cl[top]=g,cr[top]=map[nsl];break;
			}
			if(a[i]&&map.find(nsl-a[i])!=map.end())++top,cl[top]=g,cr[top]=map[nsl-a[i]],g=0;
			g=a[i]?1:g+1,nsl+=a[i+1];
		}
		dp[1]=1;
		for(int i=1;i<=top;++i){
			int p=cl[i],q=cr[i];dp[i+1]=dp[i];
			for(int j=1;j<=min(p,q);++j)dp[i+1]=(dp[i+1]+(LL)C(p,j)*C(q,j)%P*dp[i])%P;
		}
		printf("%lld\n",(LL)dp[top+1]*qpow(2,cnt)%P);
	}
	return 0;
}