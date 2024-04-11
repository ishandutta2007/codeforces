#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define N 100000
#define ll long long
using namespace std;
ll a[N+5],n,x,p,q,tmp;
inline ll read(){
	ll k=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) k=k*10+ch-48;
	return k;
}
int main(){
	n=read();
	for (ll i=1;i<=n;i++){
		x=read();
		a[x]++;
	}
	p=q=0;
	for (ll i=1;i<=N;i++){
		ll tmp=q+i*a[i];
		q=max(p,q);
		p=tmp; 
	}
	printf("%I64d",max(p,q));
}