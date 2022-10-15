#include <cstdio>
#include <cctype>
#include <algorithm>
#define re register
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,m,a[1001][1001],b[1001][1001];
inline void work(){
	n=read(),m=read();
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=m;j++)
			a[i][j]=read();
	for(re int i=1;i<=m;i++)
		for(re int j=1;j<=n;j++)
			b[i][j]=read();
	for(re int i=2;i<=m;i++){
		bool flg=0;
		for(re int j=1;j<=n;j++)
			if(b[i][j]==a[1][1]){
				for(re int k=1;k<=n;k++)
					swap(b[i][k],b[1][k]);
				flg=1;break;
			}
		if(flg)break;
	}
	for(re int i=1;i<=n;i++)
		for(re int j=i+1;j<=n;j++)
			if(b[1][i]==a[j][1]){
				for(re int k=1;k<=m;k++)
					swap(a[i][k],a[j][k]);
				break;
			}
	for(re int i=1;i<=n;i++,puts(""))
		for(re int j=1;j<=m;j++)
			printf("%d ",a[i][j]);
}
int main(){
	int t=read();
	while(t--)work();
	return 0;	
}