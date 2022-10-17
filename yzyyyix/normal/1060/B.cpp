#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi fisrt
#define se second
#define N 110 
#define M 
using namespace std;

ll m,n,cb,t,a,b;
char str[N];

inline ll ct(ll u)
{
	ll res=0;
	for(;u;)
	{
		res+=u%10;
		u/=10;
	}
	return res;
}

inline ll get(ll u)
{
	ll res=0;
	for(;u;)
	{
		res++;
		u/=10;
	}
	return res;
}

int main()
{
	ll i,j;
	cin>>n;
	t=get(n);
	t--;
	for(i=1;i<=t;i++)
	{
		a*=10;
		a+=9;
	}
	b=n-a;
	cout<<ct(a)+ct(b);
}