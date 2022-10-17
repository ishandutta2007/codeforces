#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
int l,r;
inline void work(){
	l=read(),r=read();
	if(l*2-1<=r)printf("%d\n",(r-1)/2);
	else printf("%d\n",r-l);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}