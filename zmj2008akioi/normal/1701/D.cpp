#include <cstdio>
#include <queue>
#include <vector>
const int N=5e5+10;
int T,n,ans[N];
struct pr{
	int id,v;
	pr(){};
	pr(int id,int v):id(id),v(v){};
	inline bool operator<(const pr &nxt)const{return v>nxt.v;}
};std::vector<pr> vec[N];std::priority_queue<pr> heap;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)vec[i].clear();
		for(int w,i=1;i<=n;++i){
			scanf("%d",&w);
			if(!w)vec[i+1].push_back(pr(i,n));
			else if(i==w)vec[1].push_back(pr(i,1));
			else vec[i/(w+1)+1].push_back(pr(i,i/w));
		}
		for(int i=1;i<=n;++i){
			for(pr j:vec[i])heap.push(j);
			pr t=heap.top();heap.pop(),ans[t.id]=i;
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}