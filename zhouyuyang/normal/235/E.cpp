#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
using namespace std;
const int N=2005;
int A[N],B[N],C[N],mu[N],fl[N];
int a,b,c,ans,lcm[N][N],gcd[N][N];
vector<int> vec[N];
int F(int *a,int n){
	For(i,1,n) For(j,2,n/i) a[i]+=a[i*j];
}
int main(){
	For(i,2,N-1) For(j,2,(N-1)/i) fl[j*i]=1;
	For(i,1,N-1){
		mu[i]=1;
		For(j,2,i)
			if (!fl[j])
				if (i%(j*j)==0) mu[i]=0;
				else if (i%j==0) mu[i]*=-1;
	}
	scanf("%d%d%d",&a,&b,&c);
	For(i,1,a) A[i]=a/i;
	For(i,1,b) B[i]=b/i;
	For(i,1,c) C[i]=c/i;
	int n=max(a,max(b,c));
	F(A,n); F(B,n); F(C,n);
	For(g,1,n) For(i,1,n/g) For(j,1,n/i/g)
		lcm[i*g][j*g]=i*j*g,gcd[i*g][j*g]=g;
	For(i,1,n) if (mu[i])
		For(j,1,n) if (mu[j]&&lcm[i][j])
			vec[i].push_back(j);
	For(i,1,a) For(j,0,(int)vec[i].size()-1){
		int J=vec[i][j];
		if (lcm[i][J]>a) continue;
		int id=(vec[i].size()<vec[J].size()?i:J);
		For(k,0,(int)vec[id].size()-1){
			int K=vec[id][k];
			if (lcm[i][K]>b||lcm[J][K]>c) continue;
			ans+=mu[i]*mu[J]*mu[K]*A[lcm[i][J]]*B[lcm[i][K]]*C[lcm[J][K]];
		}
	}
	printf("%d",ans&((1<<30)-1));
}