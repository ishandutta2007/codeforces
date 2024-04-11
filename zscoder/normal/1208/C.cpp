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

int a[2222][2222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int cur=0;
	for(int i=0;i<n/2;i++)
	{
		for(int j=0;j<n/2;j++)
		{
			a[i*2][j*2+1]=cur*4;
			a[i*2+1][j*2+1]=cur*4+3;
			a[i*2][j*2]=cur*4+1;
			a[i*2+1][j*2]=cur*4+2;
			cur++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j];
			if(j+1<n) cout<<' ';
		}
		cout<<'\n';
	}
}