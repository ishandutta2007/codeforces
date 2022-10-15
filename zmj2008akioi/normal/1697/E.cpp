#include <cstdio>
#include <bitset>
const int inf=1e9,harry=998244353,N=110;
int n,cnt,x[N],y[N],f[N],md[N],prd[N],C[N][N];
long long ans;
bool tag[N];
std::bitset<N> bit[N];
inline int abs(int x){return x>0?x:(-x);}
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
inline int dist(int i,int j){return abs(x[i]-x[j])+abs(y[i]-y[j]);}
int main(){
	scanf("%d",&n),prd[0]=1;
	for(int i=0;i<=n;++i)C[i][0]=1;
	for(int i=1;i<=n;++i)prd[i]=(long long)prd[i-1]*i%harry;
	for(int i=1;i<=n;++i)for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%harry;
	for(int i=1;i<=n;++i)scanf("%d %d",&x[i],&y[i]);
	for(int i=1;i<=n;++i){
		md[i]=inf,bit[i][i]=1;
		for(int j=1;j<=n;++j)if(i!=j)cmin(md[i],dist(i,j));
		for(int j=1;j<=n;++j)if(dist(i,j)==md[i])bit[i][j]=1;
		for(int j=1;j<i;++j)if(bit[i][j])tag[i]=true;
	}
	f[0]=1;
	for(int i=1;i<=n;++i){
		if(tag[i])continue;
		bool flag=true;
		for(int j=1;j<=n;++j)if(bit[i][j]&&bit[i]!=bit[j])flag=false;
		if(flag){
			int l=bit[i].count()-1;
			for(int i=n;i>=l;--i)f[i]=(f[i]+f[i-l])%harry;
		}
	}
	for(int i=0;i<=n;++i)ans+=(long long)f[i]*C[n][i]%harry*prd[n-i]%harry;
	printf("%lld",ans%harry);
	return 0;
}