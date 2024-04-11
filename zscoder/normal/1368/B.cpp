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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin>>n;
	string s = "codeforces";
	int cnt[10]={};
	for(int i=0;i<10;i++) cnt[i]=1;
	int ptr=0;
	ll prod=1;
	while(prod<n)
	{
		prod/=cnt[ptr];
		cnt[ptr]++;
		prod*=cnt[ptr];
		ptr++;
		if(ptr>=10) ptr=0;
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<cnt[i];j++) cout<<s[i];
	}
	cout<<'\n';
}