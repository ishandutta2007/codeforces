#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long LL;
const int N=1e5+10;
int T,n,a[N];
std::vector<int> A,B;
template<typename T>T min(T x,T y){return x<y?x:y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		A.clear(),B.clear();LL ans=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int w,i=1;i<=n;++i)scanf("%d",&w),ans+=w,(a[i]?B:A).push_back(w);
		std::sort(A.begin(),A.end()),std::sort(B.begin(),B.end());
		if(A.size()>B.size())A.swap(B);
		if(A.size()==B.size()){
			ans<<=1;
			ans-=min(*A.begin(),*B.begin());
		}
		else{
			std::reverse(A.begin(),A.end());
			std::reverse(B.begin(),B.end());
			for(int i=0;i<(int)A.size();++i)ans+=A[i],ans+=B[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}