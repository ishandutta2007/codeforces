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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n = s.length();
	for(int i = 1; i <= n + 1; i++)
	{
		int pos = -1; bool pp = true;
		while(pos < n)
		{
			bool posi = false;
			for(int j = i; j >= 1; j--)
			{
				if(pos+j>n) continue;
				if(pos + j == n)
				{
					posi = true;
					pos+=j;
					break;
				}
				else
				{
					if(s[pos+j]=='A'||s[pos+j]=='E'||s[pos+j]=='I'||s[pos+j]=='O'||s[pos+j]=='U'||s[pos+j]=='Y')
					{
						pos+=j;
						posi = true;
						break;
					}	
				}
			}
			if(!posi)
			{
				pp = false;
				break;
			}
		}
		if(!pp) continue;
		cout<<i;return 0;
	}
}