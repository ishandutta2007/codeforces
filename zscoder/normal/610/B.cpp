#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl; //Debug

const int INF = 1000000000;
const int MOD = 1000000009;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<long long> vll;

/*
bool compare(ii a, ii b)
{
	if(a.first < b.first)
	{
		return true;
	}
	else if(a.first > b.first)
	{
		return false;
	}
	else
	{
		if(a.second < b.second)
		{
			return true;
		}
		return false;
	}
}*/

/*bool is_prime(int n) //O(sqrt{n})
{
	for(int i = 2; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}*/

/*//Segment Tree Example
void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
*/
/*A
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	if(n % 2 != 0 || n <= 4)
	{
		cout << 0 << endl;
	}
	else
	{
		int ans = n/4;
		if(n % 4 == 0)
		{
			ans--;
		}
		cout << ans << endl;
	}
	return 0;
}*/
ll max(ll a, ll b)
{
	if(a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
vi mins;
ll arr[200010];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll minimum = INF+1;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(arr[i] < minimum)
		{
			minimum = arr[i];
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == minimum)
		{
			mins.push_back(i);
		}
	}
    ll dist = 0;
	for(int i = 1; i < mins.size(); i++)
	{
		dist = max(mins.at(i) - mins.at(i-1) - 1, dist);
	}
	dist = max(mins.at(0) + n - mins.at(mins.size() - 1) - 1, dist);
	ll ans;
	ans = n*minimum+dist;
	cout << ans << endl;
	return 0;
}
/*
int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}*/