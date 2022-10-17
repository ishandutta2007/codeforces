#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
ll n;
inline void work(){
	n=read();
	for(ll i=1;i*i*i<n;i++){
		ll x=n-i*i*i,y,z;
		double num=pow(x,1.0/3);
		y=floor(num),z=ceil(num);
		if(num-y>z-num)y=z;
		if(fabs(num-y)<1e-9)return (void)puts("YES");
	}
	puts("NO");
}
int main(){
	int t=read();
	while(t--)work();
	return 0;	
}