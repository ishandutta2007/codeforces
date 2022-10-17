#include<bits/stdc++.h>
#define LL long long

using namespace std;

inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
LL T,a,b,n;
int main(){
	T=read();
	while(T--){
		a=read(); b=read(); n=read();
		LL d=a-b;
		d*=n/2; if (n&1) d+=a;
		cout<<d<<"\n";
	}
	return 0;
}