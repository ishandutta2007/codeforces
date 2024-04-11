#include <cstdio>
#include <set>
const int N=110;
int T,n,a[N];
bool check(int k){
	std::multiset<int> set;
	for(int i=1;i<=n;++i)set.insert(a[i]);
	for(int i=k;i;--i){
		auto it=set.upper_bound(i);
		if(it!=set.begin())set.erase(--it);
		else return false;
		if(set.size())set.erase(set.begin());
	}
	return true;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;;++i)if(!check(i)){printf("%d\n",i-1);break;}
	}
	return 0;
}