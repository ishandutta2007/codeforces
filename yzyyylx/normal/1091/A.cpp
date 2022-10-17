#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 
#define M 
using namespace std;

ll n,a,b,c;

int main()
{
	ll i,j;
	cin>>a>>b>>c;
	cout<<min(min(a+1,b),c-1)*3;
}