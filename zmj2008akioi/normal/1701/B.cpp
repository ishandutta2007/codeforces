#include <cstdio>
const int N=2e5+10;
int T,n;
bool vis[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)vis[i]=false;
		puts("2");
		for(int i=1;i<=n;++i){
			int t=i;
			while(t<=n&&!vis[t])printf("%d ",t),vis[t]=true,t<<=1;
		}
		putchar('\n');
	}
	return 0;
}