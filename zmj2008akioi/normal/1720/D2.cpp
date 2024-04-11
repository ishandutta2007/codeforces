#include <cstdio>
const int N=3e5+10,M=1e7+10;
int T,n,ans,a[N],dp[N];
void cmax(int &x,int y){if(x<y)x=y;}
namespace TR{
	const int P=30;
	int tnt,tr[M][2],f[M][2][2];
	int g(int &x){return x?x:x=++tnt;}
	void clr(){
		while(~tnt){
			tr[tnt][0]=tr[tnt][1]=0;
			f[tnt][0][0]=f[tnt][0][1]=0;
			f[tnt][1][0]=f[tnt][1][1]=0;
			--tnt;
		}
		tnt=0;
	}
	void insert(int x){
		int u=0;
		for(int i=P-1;~i;--i){
			int b1=(a[x]>>i)&1,b2=(x>>i)&1;
			cmax(f[u][b1][b2],dp[x]),u=g(tr[u][b1^b2]);
		}
	}
	int fq(int x){
		int u=0,res=0;
		for(int i=P-1;~i;--i){
			int b2=(a[x]>>i)&1,b1=(x>>i)&1;
			cmax(res,f[u][b1][b2^1]);if(!(u=tr[u][b1^b2]))break;
		}
		return res;
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0,TR::clr();
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			cmax(ans,dp[i]=TR::fq(i)+1),TR::insert(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}