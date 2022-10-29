#include <bits/stdc++.h>
#define maxn 210
#define mod 10007
using namespace std;
typedef long long ll;
int tmp[maxn<<1][maxn<<1];
int M,N,b24,b25,b26,ans,f[maxn][maxn][maxn],n,m;
char s[maxn];
struct matrix{
	int a[maxn<<1][maxn<<1];
	matrix(){memset(a,0,sizeof(a));}
	void operator*=(const matrix& ma){
		for(int i=1;i<=M;++i)
			for(int k=1;k<=M;++k)if(a[i][k])
				for(int j=1;j<=M;++j)if(ma.a[k][j])
					tmp[i][j]=(tmp[i][j]+(ll)a[i][k]*ma.a[k][j])%mod;
		for(int i=1;i<=M;++i)
			for(int j=1;j<=M;++j)
				a[i][j]=tmp[i][j],tmp[i][j]=0;
	}
	void print(){
		for(int i=1;i<=M;++i,puts(""))
			for(int j=1;j<=M;++j)
				printf("%d ",a[i][j]);
		puts("----------------");
	}
}A,B,C,D;
int cal(int x,int y,int z){
	if(z<0)return 0;
	if(~f[x][y][z])return f[x][y][z];
	if(x==y)return z==0;
	int ans=0;
	if(s[x]==s[y]){
		if(x+1==y)return z==0;
		else ans=cal(x+1,y-1,z);
	} else ans=cal(x+1,y,z-1)+cal(x,y-1,z-1);
	return f[x][y][z]=ans%mod;
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%s%d",s,&n);
	n+=(m=strlen(s)),N=n;
	
	b24=m;
	b25=(m+1)/2;
	b26=b25;
	M=b24+b25+b26;
	for(int i=1;i<=b24;++i)A.a[i][i]=24,A.a[i][i+1]=1;
	for(int i=1;i<=b25;++i)A.a[i+b24][i+b24]=25,A.a[i+b24][i+b24+1]=1,A.a[i+b24][M-i+1]=1;
	for(int i=b24+b25+1;i<=M;++i)A.a[i][i]=26;
	for(int i=1;i<=M;++i)B.a[i][i]=1;
	for(N=(N-1)/2,D=A;N;N>>=1,D*=D)if(N&1)B*=D;
	C=B,B*=A;
//	C.print();
	for(int i=0;i<m;++i){
		int wi=cal(0,m-1,i);
//		printf("{%d,%d}",i,wi);
//		printf("{%d,%d}",B.a[b24-i+1][M-(m-i+1)/2+1],C.a[b24-i+1][M-(m-i+1)/2+1]);
		ans=(ans+1ll*wi*B.a[b24-i+1][M-(m-i+1)/2+1])%mod;
		if((m-i)%2==0&&n%2)ans=(ans-1ll*wi*C.a[b24-i+1][(m-i+1)/2+b24])%mod;
	}
	printf("%d",(ans%mod+mod)%mod);
}