#include <cstdio>
#include <set>
const int N=1e5+10;
int T,n,a[N],ans[N];std::set<int> set;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),set.clear();
		for(int i=1;i<=n;++i)set.insert(i),ans[i]=1,scanf("%d",&a[i]);
		for(int i=1;i<n;++i){
			if(a[i]<a[i+1])continue;
			auto it=set.lower_bound(a[i]-a[i+1]);
			int p=*it;ans[p]=i+1,set.erase(p);
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);putchar('\n');
	}
	return 0;
}