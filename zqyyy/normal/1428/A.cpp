#include <cstdio>
#include <cctype>
#define re register
#define y1 y1___
#define abs(x) ((x)<0?-(x):(x))
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int x1,y1,x2,y2;
inline void work(){
	x1=read(),y1=read(),x2=read(),y2=read();
	if(x1==x2)printf("%d\n",abs(y1-y2));
	else if(y1==y2)printf("%d\n",abs(x1-x2));
	else printf("%d\n",abs(x1-x2)+abs(y1-y2)+2);
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}