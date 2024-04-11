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

int n, t;

void up(string &s)
{
	int i = s.length() - 1;
	while(i >= 0 && s[i] == '9')
	{
		s[i--] = '0';
	}
	//cerr << s << '\n';
	if(i>=0) s[i]++;
	else
	{
		string t = s;
		s = "1";
		s += t;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> t;
	string s;
	cin >> s;
	int pos = s.find('.');
	int idx = pos+1;
	while(idx<s.length()&&s[idx]<'5') idx++;
	if(idx>=s.length()){cout<<s; return 0;}
	int l = s.length();
	while(idx > pos && s[idx] >= '5' && t)
	{
		if(idx - 1 == pos)
		{
			s = s.substr(0, pos);
			//cout<<s<<'\n';
			up(s);
			cout<<s;
			return 0;
		}
		s[idx-1]++;
		for(int i = idx; i < l; i++)
		{
			s[i] = '0';
		}
		l = idx; idx--;
		t--;
	}
	l = s.length()-1;
	while(s[l]=='0') l--;
	cout<<s.substr(0,l+1);
}