#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
int n,s;
inline void work(){
	n=read(),s=read();
	if(n&1)n-=n/2;
	else n-=n/2-1;
	printf("%d\n",s/n);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}