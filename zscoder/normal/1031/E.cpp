#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<pair<int,ii> > moves;
int a[111111];

void add_move(int x, int d, bool app=0)
{
	moves.pb(mp(x,mp(x+d,x+2*d)));
	if(app){a[x]^=1; a[x+d]^=1; a[x+d+d]^=1;}
}

void out()
{
	cout<<"YES\n";
	cout<<moves.size()<<'\n';
	for(int i=0;i<moves.size();i++)
	{
		cout<<moves[i].fi+1<<' '<<moves[i].se.fi+1<<' '<<moves[i].se.se+1<<'\n';
	}
}


void brute(vi vec, int shift=0)
{
	int n=vec.size();
	map<vi,int> dist;
	map<vi,ii> par;
	dist[vec]=0; 
	queue<vi> Q; Q.push(vec);
	while(!Q.empty())
	{
		vi v = Q.front(); int dd=dist[v]; Q.pop();
		for(int i=0;i<n;i++)
		{
			for(int d=1;i+2*d<n;d++)
			{
				v[i]^=1; v[i+d]^=1; v[i+d+d]^=1;
				if(dist.find(v)==dist.end())
				{
					dist[v]=dd+1; par[v]=mp(i,d); Q.push(v);
				}
				v[i]^=1; v[i+d]^=1; v[i+d+d]^=1;
			}
		}
	}
	vi emp(n,0);
	if(dist.find(emp)==dist.end()){cout<<"NO\n"; exit(0);}
	while(emp!=vec)
	{
		ii p = par[emp];
		add_move(p.fi+shift,p.se,1);
		emp[p.fi]^=1; emp[p.fi+p.se]^=1; emp[p.fi+p.se*2]^=1;
	}
}

map<vi,int> dist;
map<vi,ii> par;
queue<vi> Q; 
void brute2(int n=6)
{
	vi emp(n,0);
	dist[emp]=0;
	Q.push(emp);
	while(!Q.empty())
	{
		vi v = Q.front(); int dd=dist[v]; Q.pop();
		for(int i=0;i<n;i++)
		{
			for(int d=1;d<=n;d++)
			{
				if(i-2*d+6<0) continue;
				v[i]^=1; 
				if(i-d>=0) v[i-d]^=1; 
				if(i-2*d>=0) v[i-2*d]^=1;
				if(dist.find(v)==dist.end())
				{
					dist[v]=dd+1; par[v]=mp(i,d); Q.push(v);
				}
				v[i]^=1; 
				if(i-d>=0) v[i-d]^=1; 
				if(i-2*d>=0) v[i-2*d]^=1;
			}
		}
	}
}

void move2(vi vec, int shift=0)
{
	vi emp(int(vec.size()),0);
	assert(dist[vec]<=2);
	while(emp!=vec)
	{
		ii p = par[vec];
		add_move(p.fi-p.se*2+shift,p.se,1);
		vec[p.fi]^=1; 
		if(p.fi-p.se>=0) vec[p.fi-p.se]^=1;
		if(p.fi-p.se*2>=0) vec[p.fi-p.se*2]^=1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	brute2();
	for(int i=n-1;i-5>=6;i-=6)
	{
		//solve [i-5,i]
		vi vec;
		for(int j=i-5;j<=i;j++)
		{
			vec.pb(a[j]);
		}
		move2(vec,i-5);
		/*
		for(int j=0;j<n;j++)
		{
			cerr<<a[j]<<' ';
		}
		cerr<<'\n';
		*/
	}
	vi vec;
	for(int i=0;i<=min(10,n-1);i++) vec.pb(a[i]);
	brute(vec);
	out();
}