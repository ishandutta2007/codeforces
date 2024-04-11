#include <cstdio>
const int N=1e6+10;
int T,n,m,a[N];
bool ans[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;++i)ans[i]=false;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			int x=a[i],y=m+1-a[i];
			if(x>y)x^=y^=x^=y;
			if(!ans[x])ans[x]=true;
			else ans[y]=true;
		}
		for(int i=1;i<=m;++i)putchar(ans[i]?'A':'B');
		putchar('\n');
	}
	return 0;
}