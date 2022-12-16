#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define I64	long long
#define INF	(1ll<<60)
#define For(i,a,b)	for(int i=a;i<=b;i++)

I64		N;
char	s[100005];
int		M,D,A[3000005][4];

struct	Mat{
		I64 A[4][4];
		Mat()	{memset(A,0,sizeof(A));}
		Mat	operator * (const Mat&b){
			Mat	c;
			For(i,0,3)	For(j,0,3)	{
				c.A[i][j]=INF;
				For(k,0,3)	c.A[i][j]=min(c.A[i][j],A[i][k]+b.A[k][j]);
			}	return	c;
		}
		Mat	operator ^ (I64 k){
			Mat	ret,a=*this;
			for	(;k;k>>=1,a=a*a)
				if	(k&1)	ret=ret*a;
			return	ret;
		}
}S;

void	DFS(int u,int s,int d){
		For(i,0,3)	if	(A[u][i])	DFS(A[u][i],s,d+1);
			else	S.A[s][i]=min(S.A[s][i],1ll*d);
}
bool	check(I64 K){
		Mat	ret=S^K;I64	x=1ll<<60;
		For(i,0,3)	For(j,0,3)	x=min(x,ret.A[i][j]);
		return	x<N;
}

int		main(){
		scanf("%I64d%s",&N,s+1);M=strlen(s+1); 
		For(i,1,M){
			for	(int x=0,j=i;j<=i+30&&j<=M;x=A[x][s[j]-'A'],j++)
				if	(!A[x][s[j]-'A']) A[x][s[j]-'A']=++D;
		}	I64	L=0,R=N;
		For(i,0,3)	For(j,0,3)	 S.A[i][j]=INF;
		For(i,0,3)	if	(A[0][i])DFS(A[0][i],i,1); 
		for	(;L+1<R;){
			I64	Mid=L+R>>1;
			check(Mid)?L=Mid:R=Mid;
		}	printf("%I64d\n",L+1);
}