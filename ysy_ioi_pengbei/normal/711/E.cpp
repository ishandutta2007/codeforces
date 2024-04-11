#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
ll a,b,n,k,mod=1000003;
ll qp(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod; b>>=1;
	}
	return ans;
}
ll ny(ll s)
{
	return qp(s,mod-2);
}
ll ss(ll x)
{
	--x;
	ll ans=x;
	while(x) ans-=x&1, x>>=1;
	return ans;
}
int main()
{
	cin>>n>>k;
	//todo: no solution
	{
	ll cur=1;
	for(ll i=1;i<=n;i++)
	{
		cur*=2;
		if(cur>=k) break;
	}
	if(cur<k) {puts("1 1"); return 0;}
	}
	ll n2=qp(2,n);
	ll fm=qp(n2,k-1);
	ll yf=qp(ny(2),ss(k));
	ll B=fm*yf%mod;
	ll A=1;
	if(k>mod+2) A=0;
	else for(ll i=1;i<=k-1;i++) A=A*(n2-i)%mod;
	A=A*yf%mod;
	A=B-A; A=(A%mod+mod)%mod;
	B=(B%mod+mod)%mod;
	cout<<A<<" "<<B<<"\n";
}