#include <cstdio>
typedef long long LL;
const int N=70,P=998244353;
int T,n,C[N][N];
void init(){
	const int n=60;C[0][0]=1;
	for(int i=1;i<=n;++i)for(int j=0;j<=i;++j)C[i][j]=(C[i-1][j]+(j?C[i-1][j-1]:0))%P;
}
int main(){
	init(),scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		LL ans1=0,ans2=0;bool tag=true;
		for(int i=n;i;i-=2,tag=!tag){
			int t=C[i-2][(i-2)>>1],p=C[i-2][i>>1];
			if(tag)ans1+=t+p,ans2+=p;
			else ans1+=p,ans2+=t+p;
		}
		printf("%lld %lld 1\n",ans1%P,ans2%P);
	}
	return 0;
}