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
/*C
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
*/


int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	ll x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	ll tmp, tmp2;
	if(x1 > x2)
	{
		tmp = x1;
		tmp2 = y1;
		x1 = x2;
		y1 = y2;
		x2 = tmp;
		y2 = tmp2;
	}
	if(x2 > x3)
	{
		tmp = x2;
		tmp2 = y2;
		x2 = x3;
		y2 = y3;
		x3 = tmp;
		y3 = tmp2;
	}
	if(x1 > x2)
	{
		tmp = x1;
		tmp2 = y1;
		x1 = x2;
		y1 = y2;
		x2 = tmp;
		y2 = tmp2;
	}
	//cout << x1 << " " << x2 << " " << x3 << " " << y1 << " " << y2 << " " << y3 << endl;
	if(x1 != x2 && x2 != x3 && x1 != x3 && y1 != y2 && y1 != y3 && y2 != y3) //all distinct x, y coord
	{
		cout << 3;
	}
	else if(x1 == x2 && x2 == x3) //all same x-coord
	{
		cout << 1;
	}
	else if(y1 == y2 && y2 == y3) //all same y-coord
	{
		cout << 1;
	}
	else if(x1 == x2)
	{
		if(y3 > min(y1, y2) && y3 < max(y1, y2))
		{
			cout << 3;
		}
		else
		{
			cout << 2;
		}
	}
	else if(x2 == x3)
	{
		//cout << "Here" << endl;
		if(y1 > min(y2, y3) && y1 < max(y2, y3))
		{
			cout << 3;
		}
		else
		{
			cout << 2;
		}
	}
	else if(y1 == y2)
	{
		if(x3 > min(x1, x2) && x3 < max(x1, x2))
		{
			cout << 3;
		}
		else
		{
			cout << 2;
		}
	}
	else if(y2 == y3)
	{
		if(x1 > min(x3, x2) && x1 < max(x3, x2))
		{
			cout << 3;
		}
		else
		{
			cout << 2;
		}
	}
	else if(y1 == y3)
	{
		if(x2 > min(x1, x3) && x2 < max(x1, x3))
		{
			cout << 3;
		}
		else
		{
			cout << 2;
		}
	}
	return 0;
}

/*E
int a[100001];
int query[100001][2];
int pref[100001];
int total[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	int n, q, k;
	cin >> n >> q >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < q; i++)
	{
		cin >> query[i][0] >> query[i][1];
	}
	pref[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		pref[i] = pref[i-1]^a[i-1];
	}
	
	int lo = 0;
	int hi = 1000000;
	int mid;
	memset(total, 0, sizeof(total));
	for(int i = 0; i <= n; i++)
	{
		
	} 
	int l, r;
	for(int i = 0; i < q; i++)
	{
		l = query[i][0];
		r = query[i][1];
		
	}
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