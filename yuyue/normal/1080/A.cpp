#include<bits/stdc++.h>
#define LL long long

using namespace std;

inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
int d(int x,int y){
	if (x%y) return x/y+1;
	return x/y;
}
int main(){
	int n=read(),m=read();
	cout<<d(2*n,m)+d(5*n,m)+d(8*n,m);
	return 0;
}