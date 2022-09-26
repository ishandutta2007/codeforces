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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int MOD = 1e9 + 7;

int a[6];
int t1[6];
vi v1[6];
int t2[6];
vi v2[6];
string s[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
string s2[6] = {"S,M", "M,L", "L,XL", "XL,XXL", "XXL,XXXL"}; 
int assign[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i = 0; i < 6; i++) cin>>a[i];
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		string S; cin>>S;
		int p = -1;
		for(int j = 0; j < 6; j++)
		{
			if(S==s[j])
			{
				p = j; break;
			}
		}
		if(p == -1)
		{
			for(int j = 0; j < 5; j++)
			{
				if(S == s2[j])
				{
					p = j; break;
				}
			}
			t2[p]++;
			v2[p].pb(i);
		}
		else
		{
			t1[p]++;
			v1[p].pb(i);
		}
	} 
	bool pos = true;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < v1[i].size(); j++)
		{
			int z = v1[i][j];
			if(a[i] <= 0)
			{
				pos = false;
				break;
			}
			a[i]--;
			assign[z] = i;
		}
	}
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < v2[i].size(); j++)
		{
			int z = v2[i][j];
			if(a[i] > 0)
			{
				a[i]--;
				assign[z] = i;
				continue;
			}
			else
			{
				if(a[i+1] > 0)
				{
					a[i+1]--;
					assign[z] = i+1;
					continue;
				}
				else
				{
					pos = false;
					break;
				}
			}
		}
	}
	if(pos)
	{
		cout << "YES\n";
		for(int i = 0; i < n; i++)
		{
			cout << s[assign[i]] << '\n';
		}
	}
	else
	{
		cout << "NO\n";
	}
}