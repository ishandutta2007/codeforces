#include <cstdio>
#include <queue>
const int N=2e5+10;
int T,n;char s[N];
std::priority_queue<int> heap;
int max(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,s+1);
		long long ans=0;
		for(int i=1;i<=n;++i){
			int l=i-1,r=n-i;
			if(s[i]=='L')ans+=l,heap.push(r-l);
			else ans+=r,heap.push(l-r);
		}
		while(heap.size()){
			ans+=max(0,heap.top());
			printf("%lld ",ans),heap.pop();
		}
		putchar('\n');
	}
	return 0;
}