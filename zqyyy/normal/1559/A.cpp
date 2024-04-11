#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}

inline void work(){
	int n=read(),ans=~0;
	while(n--)ans&=read();
	printf("%d\n",ans);	
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}