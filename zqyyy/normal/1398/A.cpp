#include <cstdio>
#include <cctype>
#define re register
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int MAXN=1e5+1;
int n,a[MAXN];
inline void work(){
	n=read();
	for(re int i=1;i<=n;i++)a[i]=read();
	if(a[1]+a[2]>a[n])puts("-1");
	else printf("1 2 %d\n",n);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}