#include <cstdio>
#include <algorithm>
#include <unordered_map>
const int N=3e5+10;
int n,m,f,a[N],b[N],c[N];
long long val[N];
std::unordered_map<int,long long> map[N];
template<typename T>T gcd(T x,T y){return y?gcd(y,x%y):x;}
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
long long calc(int x,long long p){
	if(p>n)return val[x];
	if(map[x].find(p)!=map[x].end())return map[x][p];
	for(int i=x;i<=n;i+=p)cmax(map[x][p],val[i]);
	return map[x][p];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d %d",&a[i],&b[i]),val[0]+=a[i],c[i]=b[i]-a[i];
	std::sort(c+1,c+n+1),scanf("%d",&m);for(int i=1;i<=n;++i)val[i]=val[i-1]+c[n+1-i];
	for(int x,y,g,i=1;i<=m;++i){
		scanf("%d %d",&x,&y),f=0;
		if(x>y)swp(x,y),f=1;if(n%(g=gcd(x,y))!=0){puts("-1");continue;}
		int t=0;while(t*y<=n&&(n-t*y)%x!=0)++t;if(t*y>n){puts("-1");continue;}
		long long lcm=1ll*x*y/g;printf("%lld\n",calc(f?(n-t*y)%lcm:t*y,lcm));
	}
	return 0;
}