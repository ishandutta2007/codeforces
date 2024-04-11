#include <iostream> 

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

ll p2[100010] , n2[100010];

void exgcd(ll a , ll b , ll &x , ll &y)
{
	if(b == 0)
	{
		x = 1 , y = 0;
		return;
	}
	exgcd(b , a % b , y , x);
	y -= (a / b) * x;
}

ll get(ll a)
{
	ll x , y;
	exgcd(a , MOD , x , y);
	return (x % MOD + MOD) % MOD;
}

string s[50] , t;
string a , b;

int f[4000010];

int kmp()
{
	int cnt = 0;
	f[0] = f[1] = 0;
	for(int i = 1 , j = 0; i < b.size(); i++)
	{
		while(j && b[i] != b[j])
			j = f[j];
		if(b[i] == b[j])
			f[i + 1] = ++j;
		else
			f[i + 1] = 0;
	}
	for(int i = 0 , j = 0; i < a.size(); i++)
	{
		while(j && a[i] != b[j])
			j = f[j];
		if(a[i] == b[j])
			j++;
		if(j == b.size())
			cnt++;
	}
	return cnt;
}

int n , q; 

ll sum[100010][26];

int main()
{
	ios::sync_with_stdio(false);
	p2[0] = n2[0] = 1;
	for(int i = 1; i <= 100000; i++)
		p2[i] = p2[i - 1] * 2 % MOD;
	for(int i = 1; i <= 100000; i++)
		n2[i] = get(p2[i]);
	cin >> n >> q;
	cin >> s[0] >> t;
	for(int i = 0; i < t.size(); i++)
	{
		string temp = "";
		temp += t[i];
		s[i + 1] = s[i];
		s[i + 1] += temp;
		s[i + 1] += s[i];
		if(s[i + 1].size() > 2000000)
			break;
	}
	for(int i = t.size(); i >= 1; i--)
	{
		for(int j = 0; j < 26; j++)
			sum[i][j] += sum[i + 1][j];
		sum[i][t[i - 1] - 'a'] = (p2[t.size() - i] + sum[i][t[i - 1] - 'a']) % MOD;
	}
	while(q--)
	{
		int k;
		cin >> k >> b;
		int t1 = 0;
		while(s[t1].size() < b.size())
			t1++;
		if(t1 > k)
			cout << 0 << endl;
		else if(t1 == k)
		{
			a = s[t1];
			cout << kmp() << endl;
		}
		else
		{
			a = s[t1];
			ll tmp[27] = {0};
			tmp[26] = kmp();
			a += "?" + s[t1]; 
			for(int i = 0; i ^ 26; i++)
			{
				a[s[t1].size()] = char(i + 'a'); 
				tmp[i] = kmp() - tmp[26] * 2;
			}
			ll ans = tmp[26] * p2[k - t1] % MOD;
			for(int i = 0; i ^ 26; i++)
				ans = (ans + ((sum[t1 + 1][i] - sum[k + 1][i]) % MOD + MOD) % MOD * n2[t.size() - k] % MOD * tmp[i] % MOD) % MOD;
			cout << ans << endl;
		}
	}
	return 0;
}