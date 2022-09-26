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

string a[101];
int b[101];
bool used[101];
bool ign[101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int coml = 0;
	for(int i = 0; i < m; i++)
	{
		cin >> b[i];
		b[i]--;
		used[b[i]] = true;
		if(i == 0)
		{
			coml = a[b[i]].length();
		}
		else
		{
			if(coml != int(a[b[i]].length()))
			{
				cout<<"No\n";
				return 0;
			}
		}
	}
	string s = "";
	for(int i = 0; i < n; i++)
	{
		if(int(a[i].length()) != coml)
		{
			ign[i] = true;
		}
	}
	for(int i = 0; i < coml; i++)
	{
			char c = '$';
			for(int j = 0; j < m; j++)
			{
				if(j == 0)
				{
					c = a[b[j]][i];
				}
				else
				{
					if(c != a[b[j]][i])
					{
						c = '$';
						break;
					}
				}
			}
			if(c == '$')
			{
				s += "?";
			}
			else
			{
				s += c;
			}
	}
	//cerr<<s<<'\n';
	bool pos = true;
	for(int i = 0; i < n; i++)
	{
		if(ign[i]) continue;
		bool cor = true;
		for(int j = 0; j < coml; j++)
		{
			if(!((a[i][j] == s[j])||(s[j] == '?')))
			{
				cor = false;
				break;
			}
		}
		if(used[i])
		{
			if(!cor) pos = false;
		}
		else
		{
			if(cor) pos = false;
		}
		if(!pos) break;
	}
	if(!pos)
	{
		cout<<"No\n";
	}
	else
	{
		cout<<"Yes\n";
		cout<<s<<'\n';
	}
}