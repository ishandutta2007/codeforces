#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}

inline void work(){
	int A=read(),B=read(),C=read();
	printf("%d %d %d\n",max(0,max(B,C)+1-A),max(0,max(A,C)+1-B),max(0,max(A,B)+1-C));
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}