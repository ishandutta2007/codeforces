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
int n,a[52];
inline void work(){
	n=read();
	for(re int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	short ans=0;int i=1;
	while(i<=n){
		while(i<n && a[i+1]-a[i]<=1) i++;
		ans++,i++;
	}
	puts(ans<=1?"YES":"NO");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}