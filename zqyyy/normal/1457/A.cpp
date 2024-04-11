#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int main(){
	int t=read();
	while(t--){
		int n=read(),m=read(),r=read(),c=read();
		printf("%d\n",max(r-1,n-r)+max(c-1,m-c));	
	}
	return 0;
}