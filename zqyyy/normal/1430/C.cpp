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
int n;
inline void work(){
	n=read();printf("2\n");
	if(n==2)return printf("1 2\n"),void();
	printf("%d %d\n%d %d\n",n-2,n,n-1,n-1);
	for(re int i=n-1;i>=3;i--)printf("%d %d\n",i-2,i);
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}