#include <cstdio>
const int N=2e5+10;
int n,q,v[N];
long long pmax,sum[N],tim[N];
//tim[i] means only open i pipes the minimal time
inline int md(int x,int y){return (x+y)>>1;}
inline long long ceil(double x){return x==(int)x?(int)x:(int)x+1;}
template<typename T>T max(T x,T y){return x>y?x:y;}
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
int bsc(int t){
	int mid,l=1,r=n;
	if(tim[n]>t)return -1;
	while(l!=r){
		mid=md(l,r);
		if(tim[mid]>t)l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+v[i];
	for(int i=1;i<=n;++i)cmax(pmax,ceil((double)sum[i]/i)),tim[i]=max(pmax,ceil((double)sum[n]/i));
	scanf("%d",&q);
	for(int t,i=1;i<=q;++i){
		scanf("%d",&t);
		printf("%d\n",bsc(t));
	}
	return 0;
}