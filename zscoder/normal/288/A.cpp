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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	if(k>n){cout<<-1<<'\n'; return 0;}
	if(n==1){cout<<"a"<<'\n'; return 0;}
	if(k==1){cout<<-1<<'\n'; return 0;}
	string s;
	for(int i=0;i<n;i++)
	{
		s+=string(1,char('a'+(i%2)));
	}
	int cnt=k-1;
	for(int i=n-1;i>=n-(k-2);i--)
	{
		s[i]=char('a'+cnt); cnt--;
	}
	cout<<s<<'\n';
}