#include <cstdio>
#include <algorithm>
const int inf=1e9,N=2e5,EXT=10;
int T,n,x,q,ans,arr[N+EXT];
bool vis[N+EXT];
int main(){
	scanf("%d",&T);
	do{
		scanf("%d %d",&n,&x);
		ans=0;
		for(register int i=1;i<=n;++i)scanf("%d",&arr[i]),vis[i]=false;
		std::sort(arr+1,arr+1+n);
		q=2;
		for(register int i=1;i<=n;++i){
			if(!vis[i]){
				while(q<=n&&arr[q]<(long long)arr[i]*x)++q;
				if(q<=n&&arr[q]==(long long)arr[i]*x)vis[q]=true,++q;
				else ++ans;
			}
		}
		printf("%d\n",ans);
	}while(--T);
	return 0;
}