#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll lINF = ll(1e18);
/*A
bool open[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int s, x;
	fill(open, false);
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		for(int j = 0; j < s; j++)
		{
			cin >> x;
			open[x-1] = true;
		}
	}
	for(int i = 0; i < m; i++)
	{
		if(open[i] == false)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}*/
/*B
vvi graph;
ll dp[100001];
ll deg[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int x, y;
	vi empty;
	for(int i = 0; i < n; i++)
	{
		graph.pb(empty);
	}
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		graph[max(x, y)].pb(min(x, y));
		deg[x]++;
		deg[y]++;
	}
	ll maximum = 0;
	ll maxlength = 1;
	fill(dp, 1);
	for(int i = 0; i < n; i++)
	{
		maxlength = 1;
		for(int j = 0; j < graph[i].size(); j++)
		{
			maxlength = max(maxlength, dp[graph[i][j]] + 1);
		}
		dp[i] = maxlength;
		//cout << dp[i] << endl;
		maximum = max(maximum, maxlength*deg[i]);
	}
	cout << maximum << endl;
	return 0;
}*/


/*C
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/

ll power(ll base, ll exp, ll mod)
{
    ll res = 1;
    while(exp > 0)
	{
        if(exp%2)
		{
			res=(res*base)%mod;
	    }
		base=(base*base)%mod;
		exp/=2;
    }
    return res;
}

vll primes;
bool is_prime[200001];
ll counter[20000];
ll dp[200001];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//cout << power(2017, 99880, MOD) << endl;
	int n;
	cin >> n;
	fill(is_prime, true);
	for(int p = 2; p * p <= 200000; p++)
    {
        if(is_prime[p])
        {
            for (int i = 2*p; i <= 200000; i += p)
			{
                is_prime[i] = false;
			}
        }
    }
	dp[0] = 0;
	dp[1] = 0;
	for(int i = 2; i <= 200000; i++)
	{
		dp[i] = dp[i-1];
		if(is_prime[i])
		{
			primes.pb(i);
			dp[i]++;
		}
		//cout << dp[i] << endl;
	}
	fill(counter, 0);
//cout << primes[0];
	ll x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		counter[dp[x]]++;
	}
	ll num = 0;
	ll the_even = 0;
	for(int i = 1; i <= primes.size(); i++)
	{
		if(counter[i]%2 == 1)
		{
			the_even = i;
			num++;
		}
		if(num > 1)
		{
			break;
		}
	}
	ll exponent = 1;
	ll p2 = (MOD-1)/2;

	for(int i = 1; i <= primes.size(); i++)
	{
		exponent = (exponent*(counter[i]+1)%p2);
	}
//	ll ans = 1;
	ll sum = 0;
	ll inner;
	ll remainder_2 = 0;
	ll remainder = 0;
	ll product = 1;
	//cout << power(2, p2-2, p2) << endl;
	for(int i = 1; i <= primes.size(); i++)
	{
		sum = counter[i]*(counter[i]+1);
		sum /= 2;
		sum %= (MOD-1);
		/*if(i < 5)
		{
			cout << counter[i] + 1 << endl;
		}*/
		inner = (exponent*power(counter[i]+1, p2-2, p2))%p2;
		if(num > 1)
		{
			remainder_2 = 0;
		}
		else if(num == 0)
		{
			remainder_2 = 1;
		}
		else if(i == the_even)
		{
			remainder_2 = 1;
		}
		if(remainder_2 == 0)
		{
			if(inner % 2 == 0)
			{
				remainder = inner;
			}
			else
			{
				remainder = inner + p2;
			}
		}
		else
		{
			if(inner % 2)
			{
				remainder = inner;
			}
			else
			{
				remainder = inner + p2;
			}
		}
		remainder = (remainder * sum)%(MOD-1);
		/*if(counter[i] > 0)
		{
			cout << sum << " " << inner << " " << remainder_2 << " " << remainder << endl;
		}*/
		if(remainder < 0)
		{
			remainder += MOD;
		}
		product = (product * power(primes[i-1], remainder, MOD))%MOD;
	}
	product %= MOD;
	if(product < 0)
	{
		product += MOD;
	}
	cout << product << endl;
	return 0;
}


/*E
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/