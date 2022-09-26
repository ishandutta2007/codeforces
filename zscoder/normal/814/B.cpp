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
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int p[10001];
int a[10001];
int b[10001];
int p2[10001];
bool used[10001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	bool first=0;
	int cntfail = 0;
	int idx=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==b[i])
		{
			p[i]=p2[i]=a[i];
		}
		else
		{
			cntfail++;
			idx=i;
			if(!first)
			{
				p[i]=b[i];
				p2[i]=a[i];
				//p assumes a goes wrong alrdy, p2 assumes b goes wrong alrdy
				first=1;
			}
			else
			{
				p[i]=a[i];
				p2[i]=b[i];
			}
		}
	}
	if(cntfail==1)
	{
		for(int i=0;i<n;i++)
		{
			if(i!=idx)
			{
				used[p[i]]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!used[i])
			{
				p[idx]=i;
				break;
			}
		}
		for(int i=0;i<n;i++)
		{
			cout<<p[i];
			if(i<n-1) cout<<' ';
		}
		cout<<'\n';
		return 0;
	}
	bool pos=1;
	for(int i=0;i<n;i++)
	{
		if(used[p[i]])
		{
			pos=0;
			break;
		}
		used[p[i]]=1;
	}
	int cnta=0; int cntb=0;
	for(int i=0;i<n;i++)
	{
		if(p[i]!=a[i])
		{
			cnta++;
		}
		if(p[i]!=b[i])
		{
			cntb++;
		}
	}
	if(cnta!=1||cntb!=1) pos=0;
	if(!pos)
	{
		for(int i=0;i<n;i++) p[i]=p2[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<p[i];
		if(i<n-1) cout<<' ';
	}
	cout<<'\n';
}