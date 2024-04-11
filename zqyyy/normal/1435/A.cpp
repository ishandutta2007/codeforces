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
int n,a[101];
inline void work(){
	n=read();
	for(re int i=1;i<=n;i++)a[i]=read();
	for(re int i=1;i<=n;i+=2)printf("%d %d ",-a[i+1],a[i]);
	puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}