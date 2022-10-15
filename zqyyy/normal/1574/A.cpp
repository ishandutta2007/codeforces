#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=107;
int n;
inline void work(){
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)putchar('(');
		for(int j=1;j<=i;j++)putchar(')');
		for(int j=2*i+1;j<=2*n;j+=2)putchar('('),putchar(')');
		putchar('\n');
	}
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}