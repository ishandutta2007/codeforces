#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
const int MOD = 1e9 + 7;
const ll INF = ll(1e18);

#define pb push_back

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	int x;
	cin >> x;
	cout << (x+4)/5;
	return 0;
}*/
/*B
vi nuts;
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	int n;
	cin >> n;
	ll count = 1;
	int a;
	//nuts.pb(0);
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		if(a)
		{
			nuts.pb(i);
		}
	}
	//nuts.pb(n-1);
	if(nuts.size() == 0)
	{
		cout << 0;
	}
	else
	{
		for(int i = 0; i < nuts.size() - 1; i++)
		{
			count *= ll(nuts[i + 1] - nuts[i]);
		}
		cout << count;
	}
	return 0;
}
*/

ll a[2001][2];
ll x[2001];
ll y[2001];
vector<pair<ll, ll> > dist;

bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
	if(a.first > b.first)
	{
		return false;
	}
	else if(a.first < b.first)
	{
		return true;
	}
	else
	{
		if(a.second > b.second)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
ll suff[2001];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	ll n, x1, x2, y1, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}	
	for(int i = 0; i < n; i++)
	{
		x[i] = (a[i][0] - x1)*(a[i][0] - x1) + (a[i][1] - y1)*(a[i][1] - y1);
		y[i] = (a[i][0] - x2)*(a[i][0] - x2) + (a[i][1] - y2)*(a[i][1] - y2);
		//cout << x[i] << " " << y[i] << endl;
		dist.pb(make_pair(x[i], y[i]));
	}
	sort(dist.begin(), dist.end(), compare);
	//cout << "PK" << endl;
	suff[n - 1] = dist[n - 1].second;
	suff[n] = 0;
	//cout << "PK" << endl;
	for(int i = n - 2; i >= 0; i--)
	{
		suff[i] = max(suff[i + 1], dist[i].second);
		//cout << "PK" << endl;
	}
	//cout << "PK" << endl;
	ll minimum;
	minimum = suff[0];
	for(int i = 0; i < n; i++)
	{
		//cout << suff[i + 1] << endl;
		minimum = min(dist[i].first + suff[i + 1], minimum);
	}
	cout << minimum;
	return 0;
}

/*
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	
	return 0;
}
*/