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
int r,g,b,w,q;
inline void work(){
	r=read(),g=read(),b=read(),w=read();
	q=(r&1)+(g&1)+(b&1);
	if(!q || q==3)return puts("Yes"),void();
	if(q==1){
		if(w&1)puts("No");
		else puts("Yes");
		return;
	}if(q==2){
		if(r && g && b && (w&1)) puts("Yes");
		else puts("No");
		return;
	}
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}