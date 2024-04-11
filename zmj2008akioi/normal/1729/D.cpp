#include <cstdio>
#include <set>
const int N=1e5+10;
int T,n,x[N],y[N];
std::multiset<int> set;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),set.clear();int ans=0;
		for(int i=1;i<=n;++i)scanf("%d",&x[i]);
		for(int i=1;i<=n;++i)scanf("%d",&y[i]);
		for(int i=1;i<=n;++i)set.insert(y[i]-x[i]);
		while(set.size()){
			int a=*set.rbegin();set.erase(set.find(a));
			auto it=set.lower_bound(-a);if(it==set.end())break;
			set.erase(it),++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}