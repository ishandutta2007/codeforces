#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef pair<ll, ll> llll;
typedef vector<llll> vllll;
typedef long double ld;
const int MOD = 1e9 + 7;
const ll INF = ll(1e18);

#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << " is " << x << endl;
#define gcd __gcd
#define forp(i, begin, end) for (__typeof(end) i = (begin); i < (end); i++)
#define form(i, begin, end) for (__typeof(end) i = (begin); i >= (end); i--)
#define scan scanf
#define print printf
#define mp make_pair

bool prime[1000001];
vector<ll> primes;
void Sieve(int n)
{
    memset(prime, true, sizeof(prime));
 
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
	for(ll i = 2; i <= n; i++)
	{
		if(prime[i])
		{
			primes.push_back(i);
		}
	}
}

bool is_prime(ll n)
{
	for(ll i = 0; primes[i]*primes[i]<=n; i++)
    {
        if(n % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}
const int N = 1e6;
ll cnt = 0;
int a[N + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	Sieve(1000000);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] == 1) cnt++;
	}
	ll ans = 0;
	bool exist_pair = false;
	sort(a, a + n);
	int x, y, z;
	for(int i = cnt; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(is_prime(a[i] + a[j]))
			{
				exist_pair = true;
				x = a[i];
				y = a[j];
				break;
			}
		}
		if(exist_pair) break;
	}
	if(!exist_pair) ans = 1;
	else ans = 2;
	if(cnt > 0)
	{
		exist_pair = false;
		for(int i = cnt; i < n; i++)
		{
			if(is_prime(a[i] + 1))
			{
				z = a[i];
				exist_pair = true;
				break;
			}
		}
		if(exist_pair) ans = max(ans, cnt + 1);
		else ans = max(ans, cnt);
	}
	cout << ans << "\n";
	if(cnt == 0)
	{
		if(exist_pair) cout << x << " " << y << "\n";
		else cout << a[0];
	}
	else
	{
		if(exist_pair)
		{
			cout << z << " ";
			for(int i = 0; i < ans - 1; i++) cout << 1 << " ";
		}
		else
		{
			if(cnt < ans)
			{
				if(ans == 1)
				{
					cout << a[0];
				}
				else
				{
					cout << x << " " << y;
				}
			}
			else
			{
				for(int i = 0; i < ans; i++)
				{
					cout << 1 << " ";
				}
			}
		}
	}
	return 0;
}