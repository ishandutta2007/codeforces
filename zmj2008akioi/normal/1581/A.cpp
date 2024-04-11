#include <cstdio>
const int harry=1e9+7;
int t,n,ans;
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d",&n);
		ans=(harry+1)/2;
		for(register int j=1;j<=2*n;++j)ans=(long long)ans*j%harry;
		printf("%d\n",ans);
	}
	return 0;
}