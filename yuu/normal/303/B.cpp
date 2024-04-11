#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n, m, x, y, a, b;
int main(){
	cin>>n>>m>>x>>y>>a>>b;
	ll d=__gcd(a, b);
	a/=d;
	b/=d;
	ll scale=min(n/a, m/b);
	a*=scale;
	b*=scale;
	ll ansx=0;
	ansx=x-(a+1)/2;
	if(ansx>n-a) ansx=n-a;
	if(ansx<0) ansx=0;
	ll ansy=0;
	ansy=y-(b+1)/2;
	if(ansy>m-b) ansy=m-b;
	if(ansy<0) ansy=0;
	cout<<ansx<<' '<<ansy<<' '<<ansx+a<<' '<<ansy+b<<'\n';
}