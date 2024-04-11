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
const int MAXN=5e4+1;
int n,a[MAXN];
inline void work(){
    n=read();
    for(re int i=1;i<=n;i++)a[i]=read();
    bool flg=0;
    for(re int i=1;i<n;i++)flg|=a[i]<=a[i+1];
    puts(flg?"YES":"NO");
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}