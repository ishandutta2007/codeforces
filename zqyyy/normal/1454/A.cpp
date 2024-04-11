#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=105;
int main(){
	int T=read();
	while(T--){
		int n=read();
		for(int i=n;i;i--){
			if(n&1 && i==(n+1)/2)cout<<i-1<<" "<<i<<" ",i--;
			else cout<<i<<" ";
		}
		puts("");
	}
	return 0;
}