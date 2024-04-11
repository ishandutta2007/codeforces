#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
int n,a[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	ll L=2;
	for(int i=1;i<=n;i++){
		L=lcm(L,i+1);
		if(L>1e9)break;
		if(a[i]%L==0){puts("NO");return;}
	}
	puts("YES");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;	
}