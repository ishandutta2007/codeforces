#include <bits/stdc++.h>
#define re register
#define max(x,y) ((x)>(y)?(x):(y))
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
		int a=read(),b=read(),c=read(),d=read();
		cout<<max(a+b,c+d)<<endl;
	}
	return 0;
}