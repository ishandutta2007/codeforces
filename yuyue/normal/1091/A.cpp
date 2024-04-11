#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int a,b,c;
int main(){
	a=read(); b=read(); c=read(); b--; c-=2;
	int d=min(a,min(b,c));
	cout<<3*d+3<<"\n";
	return 0;
}