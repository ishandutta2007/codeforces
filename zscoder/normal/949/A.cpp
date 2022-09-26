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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int a[211111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s; int n=s.length();
	int cnt[2]={0,0};
	for(int i=0;i<n;i++)
	{
		a[i]=s[i]-'0'; cnt[a[i]]++;
	}
	if(cnt[1]>=cnt[0])
	{
		cout<<-1<<'\n'; return 0;
	}
	int k = cnt[0] - cnt[1];
	vector<vi> V(k);
	set<int> S[2];
	for(int i=0;i<k;i++) S[0].insert(i);
	for(int i=0;i<n;i++)
	{
		if(S[a[i]].empty())
		{
			cout<<-1<<'\n'; return 0;
		}
		int tmp = (*S[a[i]].begin());
		V[tmp].pb(i);
		S[a[i]].erase(tmp); S[a[i]^1].insert(tmp);
	}
	cout<<k<<'\n';
	for(int i=0;i<k;i++)
	{
		cout<<V[i].size()<<' ';
		for(int j=0;j<V[i].size();j++)
		{
			cout<<V[i][j]+1;
			if(j+1<V[i].size()) cout<<' ';
		}
		cout<<'\n';
	}
}