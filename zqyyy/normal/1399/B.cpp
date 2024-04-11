#include <cstdio>
#include <cctype>
#define re register
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,ma,mb,a[51],b[51];
inline void work(){
	n=read();ma=2e9,mb=2e9;
	for(re int i=1;i<=n;i++)a[i]=read(),ma=min(ma,a[i]);
	for(re int i=1;i<=n;i++)b[i]=read(),mb=min(mb,b[i]);
	for(re int i=1;i<=n;i++)a[i]-=ma,b[i]-=mb;
	long long ans=0;
	for(re int i=1;i<=n;i++)ans+=max(a[i],b[i]);
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}