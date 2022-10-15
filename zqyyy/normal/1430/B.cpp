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
const int MAXN=2e5+1;
int n,k,a[MAXN];
inline void work(){
	n=read(),k=read();
	for(re int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1),reverse(a+1,a+n+1);
	long long ans=0;
	for(re int i=1;i<=k+1;i++)ans+=a[i];
	printf("%lld\n",ans);
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}