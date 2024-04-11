#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int query(int i, int j)
{
	cout<<"? "<<i<<' '<<j<<'\n';
	fflush(stdout);
	int x; cin>>x; 
	return x;
}

int a[10001];
int b[10001];
int pp[10001];
int P[5111];
int Q[5111];
int used[5111];

int main()
{
	int n; cin>>n;
	int id=0;
	for(int i=0;i<n;i++)
	{
		a[i] = query(0,i);
		if(a[i]==0)
		{
			id=i;
		}
	}
	for(int i=0;i<n;i++)
	{
		b[i]=query(i,id);
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				//p[j] = q[i]
				pp[j] = i;
			}
		}
	}
	*/
	vi vec;
	for(int i=0;i<n;i++)
	{
		memset(used,0,sizeof(used));
		P[0] = i;
		bool pos=1;
		for(int j=0;j<n;j++)
		{
			Q[j] = (P[0]^a[j]);
			if(Q[j]<0||Q[j]>=n)
			{
				pos=0;
				break;
			}
			used[Q[j]]++;
		}
		if(!pos) continue;
		for(int j=0;j<n;j++)
		{
			P[j] = (Q[id]^b[j]);
			if(P[j]<0||P[j]>=n)
			{
				pos=0;
				break;
			}
			used[P[j]]++;
		}
		if(!pos) continue;
		for(int j=0;j<n;j++)
		{
			if(used[j]!=2)
			{
				pos=0;
				break;
			}
		}
		if(!pos) continue;
		for(int j=0;j<n;j++)
		{
			if(P[Q[j]]!=j)
			{
				pos=0;
				break;
			}
		}
		if(pos)
		{
			vec.pb(i);
		}
	}
	cout<<"!\n";
	fflush(stdout);
	cout<<vec.size()<<'\n';
	fflush(stdout);
	P[0] = vec[0];
	for(int j=0;j<n;j++)
	{
		Q[j] = (P[0]^a[j]);
	}
	for(int j=0;j<n;j++)
	{
		P[j] = (Q[id]^b[j]);
		cout<<P[j];
		if(j+1<n) cout<<' ';
	}
	cout<<'\n';
	fflush(stdout);
}