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

int C[333];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	for(int i=0;i<n;i++)
	{
		C[s[i]-'a']++;
	}
	int zc=C['z'-'a'];
	int oc=(n-4*zc)/3;
	for(int i=0;i<oc;i++) cout<<1<<' ';
	for(int i=0;i<zc;i++) cout<<0<<' ';
	cout<<'\n';
}