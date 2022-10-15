#include <cstdio>
const int N=1e6+10;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int lst=0,ans=0;
		for(int i=1;i<=n;++i){
			if(lst==0&&a[i]!=0)++ans;
			lst=a[i];
		}
		if(ans>2)ans=2;
		printf("%d\n",ans);
	}
	return 0;
}