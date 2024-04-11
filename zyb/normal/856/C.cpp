#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define lowbit(o) o&(-o)
#define P 998244353
#define N 4005
using namespace std;
int i,j,k,l,s,n,m,T[N][N],C[N][N],jc[N],a[15][3],F[N][15],f[N][15];
int S,Sum,sum,ans,test,x,GT;
inline int getlen(int x) {
	int s=0;
	while (x) x/=10,s++;
	return s;
}
//f[x][y] xa 
inline int work(int x,int y) {
	if (!y) {
		if (!x) return 1;
		return 0;
	}
	return (C[x+y-1][y-1]);
}
int main() {
	scanf("%d",&test);
	jc[1]=jc[0]=1;
	for (i=2;i<=2000;i++) jc[i]=1ll*jc[i-1]*i%P;
	for (i=0;i<=4000;i++) C[i][0]=1;
	for (i=1;i<=4000;i++) for (j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	while (test--) {
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%d",&x);
			s=getlen(x);
			a[x%11][s&1]++;
			S+=s;
		}
		f[0][0]=1;
		for (i=0;i<11;i++) {
			for (j=0;j<=sum;j++) for (k=0;k<11;k++) {
				if (!f[j][k]) continue;
				for (l=a[i][0];l>=0;l--) (T[j+l][(k+l*i*10+(a[i][0]-l)*i)%11]+=1ll*f[j][k]*C[a[i][0]][l]%P)%=P;
			}
			sum+=a[i][0];
			for (j=0;j<=sum;j++) for (k=0;k<11;k++) f[j][k]=T[j][k],T[j][k]=0;
		}
		F[0][0]=1;
		for (i=0;i<11;i++) {
			for (j=0;j<=Sum;j++) for (k=0;k<11;k++) {
				if (!F[j][k]) continue;
				for (l=a[i][1];l>=0;l--) (T[j+l][(k+l*i+(a[i][1]-l)*i*10)%11]+=1ll*F[j][k]*C[a[i][1]][l]%P)%=P;
			}
			Sum+=a[i][1];
			for (j=0;j<=Sum;j++) for (k=0;k<11;k++) F[j][k]=T[j][k],T[j][k]=0;
		}
		if ((S&1)&&(Sum&1)) GT=Sum/2+1;
		else GT=Sum/2;
		int jw=0;
		if (GT<Sum-GT) jw=1;
		else if (((S&1))&&(GT==Sum-GT)) jw=1;
		
		for (i=0;i<11;i++) for (j=0;j<=sum;j++) {
			int k=(11-i)%11;
			(ans+=1ll*F[GT][i]*jc[GT]%P*jc[Sum-GT]%P*f[j][k]%P*jc[j]%P*jc[sum-j]%P*work(sum-j,GT+(jw==1))%P*work(j,Sum-GT+(!jw))%P)%=P;
		}
		printf("%d\n",ans);
		ans=Sum=S=sum=0;
		memset(a,0,sizeof(a)),memset(f,0,sizeof(f)),memset(F,0,sizeof(F));
	}
}