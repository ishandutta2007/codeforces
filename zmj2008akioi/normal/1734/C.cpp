#include <cstdio>
typedef long long LL;
const int N=1e6+10;
int T,n;char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,s+1);LL ans=0;
		for(int i=1;i<=n;++i)for(int j=i;j<=n&&s[j]!='1';j+=i)ans+=i*(s[j]!='2'),s[j]='2';
		printf("%lld\n",ans);
	}
	return 0;
}