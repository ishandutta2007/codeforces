#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int minlength(string s)
{
	map<string,int> ma;
	for(int i=0;i<s.length();i++)
	{
		string t="";
		for(int j=i;j<s.length();j++)
		{
			t+=s[j];
			ma[t]++;
		}
	}
	int len=int(1e9);
	for(auto X:ma)
	{
		if(X.se==1) len=min(len,int(X.fi.length()));
	}
	return len;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	/*
	for(int i=0;i<(1<<n);i+=2)
	{
		string s;
		for(int j=0;j<n;j++)
		{
			s+="0";
			if(i&(1<<j)) s[j]='1';
		}
		bool pos=1;
		for(int i=0;i+(n-k)/2+1<s.length();i++)
		{
			if(s[i]!=s[i+(n-k)/2+1])
			{
				pos=0; break;
			}
		}
		if(pos&&minlength(s)==k)
		{
			for(int i=0;i<(n-k)/2+1;i++) cout<<s[i];
			cout<<'\n';
		}
	}
	return 0;
	*/
	
	
	if(n==k)
	{
		for(int i=0;i<n;i++) cout<<1;
		cout<<'\n';
		return 0;
	}
	if(k==1)
	{
		cout<<0;
		for(int i=1;i<n;i++) cout<<1;
		cout<<'\n';
		return 0;
	}
	if(k==2)
	{
		cout<<11;
		for(int i=2;i<n;i++) cout<<0;
		cout<<'\n';
		return 0;
	}
	else 
	{
		string s; 
		for(int i=0;i<(n-k)/2+1;i++)
		{
			s+="0";
		}
		s[1]='1';
		string t;
		for(int i=0;i<n;i++)
		{
			t+=s[i%int(s.length())];
		}
		cout<<t<<endl;
		//assert(minlength(t)==k);
	}
}