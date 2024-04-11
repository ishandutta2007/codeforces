#include<bits/stdc++.h>
#define ll long long
#define N 400000
using namespace std;

ll n,ans;
string s;

int main()
{
	ll i,j,x,y,t;
	cin>>x;
	if(x<1200) cout<<1200;
	else if(x<1400) cout<<1400;
	else if(x<1600) cout<<1600;
	else if(x<1900) cout<<1900;
	else if(x<2100) cout<<2100;
	else if(x<2300) cout<<2300;
	else if(x<2400) cout<<2400;
	else if(x<2600) cout<<2600;
	else cout<<3000;
}