#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,mo,i,j,k,C[N][N];
inline void add(int&a,const int&b){a+=b-mo;a+=a>>31&mo;}
struct atom{
	int c,s;
	inline void operator+=(const atom&rhs){add(c,rhs.c);add(s,rhs.s);}
	inline atom operator*(int k){return atom{int(1ll*c*k%mo),int(1ll*s*k%mo)};}
}f[N],g[N][N];
inline atom uni(const atom&a,const atom&b){
	return atom{int(1ll*a.c*b.c%mo),int((1ll*a.c*b.s+1ll*a.s*b.c)%mo)};
}
int main(){
	scanf("%d%d%d",&n,&m,&mo);
	for(i=**C=1;i<N;++i)for(j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	f[0]=atom{1,0};
	for(i=1;i<=m;++i)for(j=0;j<i;++j){
		int c=1,s=0;
		for(k=1;k<=i;++k)s+=abs(k-(j+1)),c++;
		f[i]+=uni(uni(f[j],atom{c,s}*C[i-1][j]),f[i-1-j]);
	}
	g[0][0]=atom{1,0};
	for(i=0;i<=n;++i)for(j=0;j<=min(i,m);++j){
		for(k=1;j+k<=m && i+k<=n;++k)g[i+k==n?n:i+k+1][j+k]+=uni(g[i][j],f[k]*C[j+k][k]);
		if(i<n)g[i+1][j]+=g[i][j];
	}
	printf("%d\n",g[n][m].s);
}