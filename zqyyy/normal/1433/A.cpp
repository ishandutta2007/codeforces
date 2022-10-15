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
inline void work(){
	int x=read(),y=x%10,z=0;
	while(x)z++,x/=10;
	printf("%d\n",(y-1)*10+(1+z)*z/2);
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}