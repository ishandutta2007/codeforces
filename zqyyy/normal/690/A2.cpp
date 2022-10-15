#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
int n;
int main(){
	n=read();
	if(n&1){
		printf("%d\n",n>>1);
	}else{
		int N=1;
		for(;(N<<1)<=n;N<<=1);
		printf("%d\n",(n-N)>>1);
	}
	return 0;
}