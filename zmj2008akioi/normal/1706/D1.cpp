#include <cstdio>
#include <set>
const int N=1e5+10;
int T,n,k,ans,a[N];
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
struct pr{
	int id,v;
	pr(){};
	pr(int id,int v):id(id),v(v){};
	inline int val()const{return a[id]/v;}
	inline bool operator<(const pr &nxt)const{return val()>nxt.val();}
};std::multiset<pr> set;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k),ans=1e6,set.clear();
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),set.insert(pr(i,1));
		while(set.size()){
			cmin(ans,set.begin()->val()-set.rbegin()->val());
			pr nw=*set.begin();set.erase(set.begin());
			if(nw.val()==1||a[nw.id]/(a[nw.id]/nw.v)+1>k)break;set.insert(pr(nw.id,a[nw.id]/(a[nw.id]/nw.v)+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}