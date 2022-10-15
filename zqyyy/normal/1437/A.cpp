#include <cstdio>
#include <cctype>
#define re register
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int l,r;
inline void work(){
	l=read(),r=read();
	if(l*2>r)puts("YES");
	else puts("NO");
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}