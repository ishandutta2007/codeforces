#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
#define mk make_pair
#define fi first
#define se second
const int N=1007;
int n,m,k,tot,b[N];
vector<int>a[N];
double C[N][N],f[N][N],g[N][N];
int main(){
	n=read(),m=read();
	for(int i=1,x;i<=m;i++){
		x=read();
		while(x--)a[i].push_back(b[++tot]=read());	
	}
	C[0][0]=1;
	for(int i=1;i<=1000;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];	
	}
	sort(b+1,b+tot+1,greater<int>());
	f[0][0]=g[0][0]=1;
	for(int i=1;i<=m;i++){
		int c1=0,c2=0;
		for(auto x:a[i])c1+=x>b[n],c2+=x==b[n];
		for(int k=0;k<=c2;k++)
			for(int j=0;j+k<=n;j++)
				g[i][j+c1+k]+=g[i-1][j],f[i][j+c1+k]+=f[i-1][j]/C[a[i].size()][c1+k];
	}
	printf("%.9lf\n",f[m][n]/g[m][n]);
	return 0;
}