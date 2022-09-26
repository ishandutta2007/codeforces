#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

/*A
int freq[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x;
	int maximum = 0;
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		freq[x]++;
		if(freq[x] > maximum)
		{
			ans = x;
			maximum = freq[x];
		}
	}
	cout << ans;
	return 0;
}
*/
bool comp(pair<int,string> a, pair<int,string>  b)
{
	if(a.fi != b.fi) return a.fi > b.fi;
	else return a.se < b.se;
}
map<string, int> ma;
vector<pair<int,string> > vec;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	string x;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		ma[x] = i;
	}
	for(map<string,int>::iterator i = ma.begin(); i != ma.end(); i++)
	{
		vec.pb(make_pair(i->se, i->fi));
	}
	sort(vec.begin(), vec.end(), comp);
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].se << endl;
	}
	return 0;
}