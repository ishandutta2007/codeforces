#include <cstdio>
#include <vector>
const int N=1e6+10;
int T,n,a[N];
std::vector<int> vec[N];
inline int max(int x,int y){return x>y?x:y;}
inline void cmax(int &x,int y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)vec[i].clear();
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			vec[a[i]].push_back(i);
		}
		for(int i=1;i<=n;++i){
			if(!vec[i].size()){printf("0 ");continue;}
			int dp[2]={0,0};
			for(int j:vec[i]){
				int bit=j&1;
				cmax(dp[bit],dp[bit^1]+1);
			}
			printf("%d ",max(dp[0],dp[1]));
		}
		putchar('\n');
	}
	return 0;
}