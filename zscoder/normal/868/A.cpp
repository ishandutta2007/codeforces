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

bool a[27][27];
string S[111];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int n; cin>>n;
	for(int i = 0; i < n; i++)
	{
		string t; cin>>t;
		a[t[0]-'a'][t[1]-'a']=1;
		S[i]=t;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[S[i][1]-'a'][S[j][0]-'a']=1;
		}
	}
	if(a[s[0]-'a'][s[1]-'a']) cout<<"YES\n";
	else cout<<"NO\n";
}