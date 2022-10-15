#include <cstdio>
#include <cctype>
#define re register
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int MAXN=3e5+1;
int n,a[MAXN],mx[MAXN],pre[MAXN],ans[MAXN]={1000000};
inline void work(){
	n=read();
	for(re int i=1;i<=n;i++)a[i]=read(),pre[i]=0,mx[i]=0,ans[i]=1e6;
	for(re int i=1;i<=n;i++)mx[a[i]]=max(i-pre[a[i]],mx[a[i]]),pre[a[i]]=i;
	for(re int i=1;i<=n;i++)mx[i]=max(n+1-pre[i],mx[i]);
	for(re int i=1;i<=n;i++)ans[mx[i]]=min(ans[mx[i]],i);
	for(re int i=1;i<=n;i++)ans[i]=min(ans[i],ans[i-1]),printf("%d ",ans[i]==1e6?-1:ans[i]);
	puts("");
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}