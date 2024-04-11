#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}

int main(){
	int T=read();
	while(T--){
		int a=read(),b=read();
		if((a+b)&1)puts("-1");
		else if(a!=b)puts("2");
		else if(a)puts("1");
		else puts("0");
	}
	return 0;	
}