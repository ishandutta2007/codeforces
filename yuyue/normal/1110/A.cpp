#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int n,m;
LL ans;
int main(){
	n=read(); m=read();
	for (int i=1;i<=m;i++){
		ans=(ans*n+read())%2;
	}
	if (ans) puts("odd");
	else puts("even");
	return 0;
}