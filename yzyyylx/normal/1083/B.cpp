#include<bits/stdc++.h>
#define ll long long
#define N 500100
using namespace std;

ll n,k,to[N][2],l,r,ans;
string a,b;

int main()
{
	ll i,j,t;
	cin>>n>>k>>a>>b;
	for(i=0;i<n&&k;i++)
	{
		t=r-l-1;
		l=l*2+a[i]-'a';
		r=r*2+b[i]-'a';
		t+=(a[i]=='a')+(b[i]=='b')+(!i);
		t=min(k,t);
		k-=t;
		ans+=t*(n-i);
	}
	cout<<ans;
}