#include<iostream>
#include<cstdio>
#include<cstdlib>
long long l,r,k,x,y,a,b;
inline void out(bool b){
	puts(b?"YES":"NO");
	exit(0);
}
int main(){
	std::cin>>l>>r>>x>>y>>k;
	a=(l+k-1)/k;
	b=r/k;
	if(a>b)out(0);
	if(a<x)out(b>=x);
		else out(a<=y);
}