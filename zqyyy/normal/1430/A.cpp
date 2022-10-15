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
int a[1010],b[1010],c[1010];
bool ok[1010];
inline void prework(){
	ok[0]=1;
	for(re int i=0;i<=1000;i++)
		if(ok[i]){
			if(!ok[i+3])ok[i+3]=1,a[i+3]=a[i]+1,b[i+3]=b[i],c[i+3]=c[i];
			if(!ok[i+5])ok[i+5]=1,a[i+5]=a[i],b[i+5]=b[i]+1,c[i+5]=c[i];
			if(!ok[i+7])ok[i+7]=1,a[i+7]=a[i],b[i+7]=b[i],c[i+7]=c[i]+1;
		}
}
inline void work(){
	int n=read();
	if(!ok[n])puts("-1");
	else printf("%d %d %d\n",a[n],b[n],c[n]);
}
int main(){
	prework();
	int t=read();
	while(t--)work();
	return 0;
}