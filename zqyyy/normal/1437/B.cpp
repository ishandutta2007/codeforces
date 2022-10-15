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
int n;
char a[100001];
inline void work(){
	n=read();scanf("%s",a+1);
	a[0]='2';int cnt0=0,cnt1=0;
	for(re int i=1;i<=n;i++)
		if(a[i]!=a[i-1] && a[i]=='1')cnt1++;
		else if(a[i]!=a[i-1] && a[i]=='0')cnt0++;
	printf("%d\n",n/2-min(cnt0,cnt1));
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}