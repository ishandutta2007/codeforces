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

/*B
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
*/

/*C
string a[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if(n == 1)
	{
		cout << 6;
		return 0;
	}
	int ans = 3;
	int dif;
	int tmpans;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			dif = 0;
			for(int k = 0; k < 6; k++)
			{
				if(a[i][k] != a[j][k]) dif++;
			}
			tmpans = (dif-1)/2;
			ans = min(ans, tmpans);
		}
	}
	cout << ans;
	return 0;
}
*/
ll obs[200001];
typedef pair<int, int> ii;
vector<ii> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m, s, d;
	cin >> m >> n >> s >> d;
	for(int i = 0; i < m; i++)
	{
		cin >> obs[i];
	}
	sort(obs, obs + m);
	ll pos = 0;
	//ll tmp;
	ll jump; ll run;
	int i = 0;
	bool possible = true;
	bool found;
	while(i < m)
	{
		found = false;
		jump = 0;
		//Run part
		run = obs[i] - 1 - pos;
		if(run < s)
		{
			possible = false;
			break;
		}
		else
		{
			ans.pb(ii(1, run));
			pos = obs[i] - 1;
		}
		//Jump part
		while(i < m - 1)
		{
			if((obs[i] + 1 - pos) <= d)
			{
				if((obs[i+1]-1-(obs[i]+1)) >= s)
				{
					jump = obs[i] + 1 - pos;
					pos = obs[i] + 1;
					i++;
					ans.pb(ii(2, jump));
					found = true;
					break;
				}
				else
				{
					i++;
				}
			}
			else
			{
				possible = false;
				break;
			}
		}
		if(!found)
		{
			if((obs[m-1]+1-pos) <= d)
			{
				jump = obs[m-1]+1-pos;
				pos = obs[m-1]+1;
				i++;
				ans.pb(ii(2, jump));
			}
			else
			{
				possible = false;
				break;		
			}
		}
	}
	if(pos < n)
	{
		ans.pb(ii(1, n - pos));
	}
	if(!possible)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		for(int i = 0; i < ans.size(); i++)
		{
			if(ans[i].fi == 1)
			{
				cout << "RUN " << ans[i].se << endl;
			}
			else
			{
				cout << "JUMP " << ans[i].se << endl;
			}
		}
	}
	return 0;
}