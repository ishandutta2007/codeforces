#include <cstdio>
const int N=110;
int T,n,ans[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);bool tag=true;
		for(int w,i=1;i<=n;++i){
			scanf("%d",&w);
			if(w&&ans[i-1]-w>=0)tag=false;
			else ans[i]=ans[i-1]+w;
		}
		if(!tag)puts("-1");
		else{
			for(int i=1;i<=n;++i)printf("%d ",ans[i]);
			putchar('\n');
		}
	}
	return 0;
}