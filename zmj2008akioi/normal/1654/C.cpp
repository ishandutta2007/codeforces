#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
int T,n,cnt,a[200010];
long long sum;
bool tag;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),sum=cnt=0;
		std::map<long long,int> map;
		std::queue<long long> queue;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum+=a[i],++map[a[i]];
		std::sort(a+1,a+1+n),queue.push(sum);
		for(int i=1;i<n;++i){
			long long nw=queue.front();queue.pop();
			long long a=nw>>1,b=(nw+1)>>1;
			if(map[a])--map[a],++cnt;
			else queue.push(a);
			if(map[b])--map[b],++cnt;
			else queue.push(b);
		}
		if(map[queue.front()])++cnt;
		queue.pop();
		puts(cnt==n?"Yes":"No");
	}
	return 0;
}