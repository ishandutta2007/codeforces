#include <cstdio>
#include <map>
typedef long long LL;
const int N=1e3+10,K=30;
int n,k,deg[N],a[N][K],cv[N][N];
std::map<LL,int> map;
LL hash(int *a){
	LL p=1,res=0;
	for(int i=1;i<=k;++i,p*=3)res+=a[i]*p;
	return res;
}
int add(int *u,int *v){
	int *b=new int[K];
	for(int i=1;i<=k;++i){
		if(u[i]==v[i])b[i]=u[i];
		else b[i]=3-u[i]-v[i];
	}
	LL nh=hash(b);
	if(map.find(nh)==map.end())return 0;
	return map[nh];
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j)scanf("%d",&a[i][j]);
		map[hash(a[i])]=i;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)continue;cv[i][j]=add(a[i],a[j]);
			if(cv[i][j])++deg[i],++deg[j],++deg[cv[i][j]];
		}
	}
	LL ans=0;
	for(int i=1;i<=n;++i){
		deg[i]/=6;
		ans+=(LL)deg[i]*(deg[i]-1)/2;
	}
	printf("%lld",ans);return 0;
}