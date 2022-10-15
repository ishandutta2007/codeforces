#include <cstdio>
#include <cctype>
#define re register
using namespace std;
#define int short
#define min(x,y) ((x)<(y)?(x):(y))
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,m,ans,a[201],b[201];
bool vis[201][201];
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;i++)a[i]=read();
	for(re int i=1;i<=m;i++)b[i]=read();
	for(re int k=8;~k;k--){
		bool flg=0;
		for(re int i=1;i<=n;i++){
			bool ok=1;
			for(re int j=1;j<=m;j++)
				if((!vis[i][j]) && (!(a[i]&b[j]&(1<<k)))){
					ok=0;
					break;
				}
			if(ok){flg=1;break;}
		}
		if(flg){ans+=(1<<k);continue;}
		for(re int i=1;i<=n;i++)
			for(re int j=1;j<=m;j++)
				if(a[i]&b[j]&(1<<k))vis[i][j]=1;
	}
	printf("%d\n",ans);
	return 0;
}