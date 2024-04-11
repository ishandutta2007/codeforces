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
inline int rd(){
	char c=getchar();
	while(!isdigit(c))c=getchar();
	return c&15;
}
const int MAXN=1e5+2;
int n,a[MAXN],s[MAXN];
inline void work(){
	n=read();
	for(re int i=1;i<=n;i++)a[i]=rd();
	for(re int i=1;i<=n;i++)s[i]=s[i-1]+a[i]-1;
	sort(s,s+n+1);
	long long ans=0;
	int i=0;
	while(i<=n){
		int x=1;++i;
		while(s[i]==s[i-1] && i<=n)x++,i++;
		ans+=1ll*x*(x-1)/2;
	}
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}