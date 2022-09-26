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

/*
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	
	return 0;
}
*/