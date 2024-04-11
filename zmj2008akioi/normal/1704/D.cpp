#include <cstdio>
#include <unordered_map>
const int N=1e5+10;
int T,n,m,cnt;
long long a[2],ps[N];
std::unordered_map<long long,int> map;
long long abs(long long x){return x>0?x:(-x);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		int p=0;map.clear();
		for(int i=1;i<=n;++i){
			long long c,sum=0,nsum=0;
			for(int j=1;j<=m;++j){
				scanf("%lld",&c);
				sum+=c,nsum+=sum;
			}
			++map[nsum],ps[i]=nsum;
		}
		cnt=0;
		for(int i=1;i<=n;++i)if(map[ps[i]]==1)p=i;
		for(auto i:map)a[cnt++]=i.first;
		printf("%d %lld\n",p,abs(a[0]-a[1]));
	}
	return 0;
}