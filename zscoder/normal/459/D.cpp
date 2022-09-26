#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

/*
//380C - Sereja and Brackets
const int MAX_N = 1e6;
const int MAX_M = 1e5;

ll t[4*MAX_N + 1];
ll o[4*MAX_N + 1];
ll c[4*MAX_N + 1];
int n;
string s;
int ask[MAX_M + 1][2];

void build(int id = 1, int l = 0, int r = n)
{
	if(r - l < 2)
	{
		if(s[l] == '(')
		{
			o[id] = 1;
		}
		else
		{
			c[id] = 1;
		}
		return ;
	}
	int mid = (l + r)/2;
	int x = 2*id;
	int y = 2*id + 1;
	build(x, l, mid);
	build(y, mid, r);
	int tmp = min(o[x], c[y]);
	t[id] = t[x] + t[y] + tmp;
	o[id] = o[x] + o[y] - tmp;
	c[id] = c[x] + c[y] - tmp;
}

iii query(int x, int y, int id = 1, int l = 0, int r = n)
{
	if(l >= y || x >= r)
	{
		return iii(0, ii(0, 0));
	}
	if(x <= l && r <= y)
	{
		return iii(t[id], ii(o[id], c[id]));
	}
	int mid = (l + r)/2;
	int g = 2*id;
	int h = g + 1;
	iii a = query(x, y, g, l, mid);
	iii b = query(x, y, h, mid, r);
	int T, O, C, temp;
	temp = min(a.second.first, b.second.second);
	T = a.first + b.first + temp;
	O = a.second.first + b.second.first - temp;
	C = a.second.second + b.second.second - temp;
	return iii(T, ii(O, C));
}

vector<ll> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	memset(t, 0, sizeof(t));
	memset(c, 0, sizeof(c));
	memset(o, 0, sizeof(o));	
	cin >> s;
	n = s.length();
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> ask[i][0] >> ask[i][1];
	}
	int left, right;
	build();
	iii answer;
	for(int i = 0; i < m; i++)
	{
		left = ask[i][0];
		right = ask[i][1];
		answer = (query(left - 1, right));
		ans.push_back(answer.first);
	}
	for(int i = 0; i < m; i++)
	{
		cout << 2*ans[i] << endl; (we want length of substring)
	}
	return 0;
}
*/

//459D - Pashmak and Parmida's problem
const int MAX_N = 1e6;

ll a[MAX_N + 1];
ll has[MAX_N + 1];
ll tree[MAX_N + 1];
ll cnt[MAX_N + 1];
ll rem[MAX_N + 1];

void update(int x, ll val)
{
	for(int i = x + 1; i < MAX_N; i += (i & (-i)))
	{
		tree[i] += val;
	}
}

ll read(int x)
{
	ll ans = 0;
	for(int i = x; i > 0; i -= (i & (-i)))
	{
		ans += tree[i];
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int counter = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		has[counter++] = a[i];
	}

    sort(has, has + counter);
    counter = unique(has, has + counter) - has;

    for (int i = 0; i < n; i++)
	{
		a[i] = lower_bound(has, has + counter, a[i]) - has;
		//cout << a[i] << endl;
	}
	
	memset(cnt, 0, sizeof(cnt));
	for (int i = n - 1; i >= 0; i--)
    {
        cnt[a[i]]++;
        update(cnt[a[i]], 1);
        rem[i] = cnt[a[i]];
    }

	memset(cnt, 0, sizeof(cnt));
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
		update(rem[i], -1);
        cnt[a[i]]++;
        ans += read(cnt[a[i]]) - read(0);
    }

    cout << ans << endl;
	return 0;
}