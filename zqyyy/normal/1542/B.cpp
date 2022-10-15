#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,a,b;
inline void work(){
	n=read(),a=read(),b=read();
	if(n==1)return (void)puts("Yes");
	ll res=1;
	for(int i=0;i<=31;i++){
		if((n-res)%b==0)return (void)puts("Yes");
		res=res*a;
		if(res>n)break;
	}
	puts("No");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}