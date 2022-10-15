#include <cstdio>
#include <vector>
#include <algorithm>
const int N=1e5,EXT=10;
int n,m,w,szr,szc;
long long ans;
std::vector<int> r[N+EXT],c[N+EXT];
int main(){
	scanf("%d %d",&n,&m);
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=m;++j){
			scanf("%d",&w);
			r[w].push_back(i),c[w].push_back(j);
		}
	}
	for(register int i=1;i<=N;++i){
		std::sort(r[i].begin(),r[i].end()),std::sort(c[i].begin(),c[i].end());
		szr=r[i].size(),szc=c[i].size();
		for(register int j=0;j<szr;++j)ans+=(long long)(1-szr+j*2)*r[i][j];
		for(register int j=0;j<szc;++j)ans+=(long long)(1-szc+j*2)*c[i][j];
	}
	printf("%lld",ans);
	return 0;
}