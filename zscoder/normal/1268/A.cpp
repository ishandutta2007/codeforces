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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string add(string t)
{
	for(int i=int(t.length())-1;i>=0;i--)
	{
		if(t[i]<'9')
		{
			t[i]++; return t;
		}
		else
		{
			t[i]='0';
		}
	}
	return t;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	string s; cin>>s;
	string tmp = s.substr(0,k);
	string a=tmp;
	for(int i=k;i<n;i++)
	{
		a+=tmp[i%k];
	}
	if(a>=s)
	{
		cout<<n<<'\n';
		cout<<a<<'\n';
		return 0;
	}
	string tmp2 = add(tmp);
	tmp=tmp2;
	a=tmp;
	for(int i=k;i<n;i++)
	{
		a+=tmp[i%k];
	}
	if(a>=s)
	{
		cout<<n<<'\n';
		cout<<a<<'\n';
		return 0;
	}
}