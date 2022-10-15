#include <cstdio>
#include <cctype>
#include <algorithm>
#define re register
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int r,g,b,x[201],y[201],z[201];
int ans,f[201][201][201];
int main(){
	r=read(),g=read(),b=read();
	for(re int i=1;i<=r;i++)x[i]=read();
	for(re int i=1;i<=g;i++)y[i]=read();
	for(re int i=1;i<=b;i++)z[i]=read();
	sort(x+1,x+r+1),reverse(x+1,x+r+1);
	sort(y+1,y+g+1),reverse(y+1,y+g+1);
	sort(z+1,z+b+1),reverse(z+1,z+b+1);
	for(re int i=0;i<=r;i++)
		for(re int j=0;j<=g;j++)
			for(re int k=(i+j)&1;k<=b;k+=2){
				if(i && j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+x[i]*y[j]);
				if(i && k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+x[i]*z[k]);
				if(j && k) f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]+y[j]*z[k]);
				ans=max(ans,f[i][j][k]);
			}
	printf("%d\n",ans);
	return 0;
}