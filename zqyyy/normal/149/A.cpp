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
int k,a[13];
int main(){
	k=read();
	for(re int i=1;i<=12;i++)a[i]=read();
	sort(a+1,a+12+1),reverse(a+1,a+12+1);
	int sum=0;
	for(re int i=0;i<=12;i++){
		sum+=a[i];
		if(sum>=k)return printf("%d\n",i),0;
	}
	puts("-1");
	return 0;
}