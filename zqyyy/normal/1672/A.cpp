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
	int n=read(),sum=0;
	for(int i=1;i<=n;i++)sum+=read()-1;
	puts(sum&1?"errorgorn":"maomao90");	
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}