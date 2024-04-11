#include <cstdio>
#include <set>
const int N=2e5+10;
int T,n,m,bkt[N];
std::multiset<int> set;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m),set.clear();
		for(int i=1;i<=n;++i)bkt[i]=0;
		for(int w,i=1;i<=m;++i)scanf("%d",&w),++bkt[w];;
		for(int i=1;i<=n;++i)set.insert(bkt[i]);
		while(*set.rbegin()-*set.begin()>2){
			int a=*set.begin(),b=*set.rbegin();
			set.erase(set.find(a)),set.erase(set.find(b));
			set.insert(a+2),set.insert(b-1);
		}
		printf("%d\n",*set.rbegin());
	}
	return 0;
}