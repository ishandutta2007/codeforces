#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;
typedef vector<iii> viii;

const int MOD = 1e9 + 7;
const ll INF = ll(1e18);

#define pb push_back
#define debug(x) cerr << #x << " = " << x << endl;
#define gcd __gcd
#define rep(i, begin, end) for (__typeof(end) i = (begin); i < (end); i++)
#define rem(i, begin, end) for (__typeof(end) i = (begin); i >= (end); i--)
//__gcd(value1, value2)
//

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	set<string> words;
	string s;
	cin >> s;
	int n = s.length();
	string word;
	rep(i, 0, n + 1)
	{
		rep(j, 0, 26)
		{
			word = "";
			rep(k, 0, i)
			{
				word.append("a");
				word[k] = s[k];
			}
			word.append("a");
			word[i] = char(j + 'a');
			rep(k, i, n)
			{
				word.append("a");
				word[k + 1] = s[k];
			}
			words.insert(word);
		}
	}
	cout << words.size() << endl;
	return 0;
}
*/

/*B
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	int ans[101];
	memset(ans, 0, sizeof(ans));

	int n;
	cin >> n;
	string s;
	vector<bitset<101> > vec;
	rep(i, 0, n)
	{
		bitset<101> a;
		//a.reset();
		cin >> s;
		rep(j, 0, n)
		{
			a.set(j, (s[j] - '0'));
		}
		vec.pb(a);
	}
	//sort(vec.begin(), vec.end());
	rep(i, 0, n)
	{
		rep(j, i + 1, n)
		{
			//cout << ans[i] << " " << ans[j] << endl;
			if(vec[i] == vec[j])
			{
				ans[i]++;
				ans[j]++;
			}
		}
	}
	
	int answer = 0;
	rep(i, 0, n)
	{
		//cout << ans[i] << endl;
		answer = max(answer, ans[i]);
	}
	answer++;
	cout << answer;
	return 0;
}
*/

int a[1001];
ll factorial[1001];
ll ans[1001];

ll power(ll base, ll exp)
{
	ll ans = 1;
    while (exp != 0) 
	{
        if (exp % 2) 
		{    // q is odd
            ans = (ans * base)%MOD;
			exp--;
        }
        base = (base * base)%MOD;
        exp /= 2;
    }
	ans %= MOD;
	if(ans < 0)
	{
		ans += MOD;
	}
    return ans;
}

ll choose(ll n, ll r)
{
	r = min(r, n - r);
	if(r == 0)
	{
		return 1;
	}
	if(r == 1)
	{
		return n%MOD;
	}
	ll res = 1;
	rem(i, n, n - r + 1)
	{
		res = (res * i)%MOD;
	}
	res = (res * power(factorial[r], MOD - 2))%MOD;
	if(res < 0)
	{
		res += MOD;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen(".txt", "r", stdin);
	int k;
	cin >> k;
	ll n = 0;
	rep(i, 0, k)
	{
		cin >> a[i];
		n += a[i];
	}
	factorial[0] = 1;
	rep(i, 1, n + 1)
	{
		factorial[i] = (i * factorial[i - 1])% MOD;
	}
	ll answer = 1;
	ll sum = a[0]-1;
	ans[0] = 1;
	rep(i, 1, k)
	{
		sum += a[i];
		ans[i] = (ans[i - 1] * choose(sum, a[i] - 1))%MOD;
	}
	answer = ans[k - 1];
	if(answer < 0)
	{
		answer += MOD;
	}
	cout << answer;
	return 0;
}

/*D
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