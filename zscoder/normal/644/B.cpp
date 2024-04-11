#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
const int MOD = 1e9 + 7;
#define fi first
#define se second
#define pb push_back
#define mp make_pair

/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	int idx = 0;
	if(a*b < n)
	{
		cout << -1;
		return 0;
	}
	else
	{
		if(b % 2 == 1)
		{
			for(int i = 0; i < a; i++)
			{
				for(int j = 0; j < b; j++)
				{
					idx++;
					if(idx <= n) cout << idx << " ";
					else cout << 0 << " ";
				}
				cout << "\n";
			}
		}
		else if(a % 2 == 1)
		{
			for(int i = 0; i < a; i++)
			{
				for(int j = 0; j < b; j++)
				{
					idx = a*j+i+1;
					if(idx <= n) cout << idx << " ";
					else cout << 0 << " ";
				}
				cout << "\n";
			}
		}
		else
		{
			for(int i = 0; i < a; i++)
			{
				for(int j = 0; j < b; j++)
				{
					if(i % 2)
					{
						idx = b*i+j+1;
						if(j % 2)
						{
							idx--;
						}
						else
						{
							idx++;
						}
					}
					else
					{
						idx = b*i+j+1;
					}
					if(idx <= n) cout << idx << " ";
					else cout << 0 << " ";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}
*/
typedef pair<ll, ll> iii;
typedef pair<iii, ll> iiii;
deque<iiii> q;
ll ans[200001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, b;
	cin >> n >> b;
	ll t = 0;
	ll x, y;
	ll tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		t = x;
		while(!q.empty() && q.front().fi.fi <= t)
		{
			ans[q.front().se] = q.front().fi.fi;
			tmp = q.front().fi.fi;
			q.pop_front();
			if(!q.empty())
			{
				q.front().fi.fi = tmp + q.front().fi.se;
			}
		}
		if(q.size() < b + 1)
		{
			q.push_back(iiii(mp(t + y, y), i));
		}
		else
		{
			ans[i] = -1;
		}
	}
	t = q.front().fi.fi;
	while(!q.empty())
	{
		ans[q.front().se] = q.front().fi.fi;
		tmp = q.front().fi.fi;
		q.pop_front();
		if(!q.empty())
		{
			q.front().fi.fi = tmp + q.front().fi.se;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}


/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/
/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/
/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/
/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/
/*
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}
*/