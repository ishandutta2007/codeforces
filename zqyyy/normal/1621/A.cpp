#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}

int n,K;
inline void work(){
	n=read(),K=read();
	if((n+1)/2<K){puts("-1");return;}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)putchar(i==j && i%2==1 && (i+1)/2<=K?'R':'.');
}
int main(){
	int test=read();
	while(test--)work();
    return 0;
}