#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
int n,m;
inline void work(){
    n=read(),m=read();
    if(n%2==1 || m%2==1)
	for(int i=1;i<=n;i++,puts(""))
	    for(int j=1;j<=m;j++)
		if((i+j)&1)putchar((i==n && j==m && (n%2==0 || m%2==0))?'B':'W');
		else putchar('B');
    else
	for(int i=1;i<=n;i++,puts(""))
	    for(int j=1;j<=m;j++)
		if((i+j)&1)putchar('B');
		else putchar((i==n && j==m)?'B':'W');
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}