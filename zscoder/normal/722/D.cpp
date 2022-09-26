#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vi a;

int numdig(int x)
{
	int tmp = x;
	int dig = 0;
	while(tmp)
	{
		tmp >>= 1; dig++;
	}
	return dig;
}

int getdig(int x, int cnt)
{
	int dig = numdig(x);
	int rem = dig - cnt;
	return (x/(1<<rem));
}

set<int> s;
int n; 

bool check(int v)
{
	//cerr << v << '\n';
	for(int i = 0; i < n; i++)
	{
		int d = numdig(a[i]); bool found = false;
		for(int j = d; j >= 1; j--)
		{
			int val = getdig(a[i], j);
			//if(v == 500000000) cerr << val << '\n';
			if(val <= v)
			{
				if(s.find(val) == s.end())
				{
					s.insert(val);
					found = true;
					break;
				}
			}
		}
		if(!found) return false;
	}
	return true;
}

void construct(int v)
{
	for(int i = 0; i < n; i++)
	{
		int d = numdig(a[i]);
		for(int j = d; j >= 1; j--)
		{
			int val = getdig(a[i], j);
			if(val <= v)
			{
				if(s.find(val) == s.end())
				{
					s.insert(val);
					break;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; a.resize(n);
	//cout << getdig(8, 2) << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	/*
	for(int i = 0; i < n; i++)
	{
		int d = numdig(a[i]);
		for(int j = 1; j <= d; j++)
		{
			s.insert(getdig(a[i], j));
		}
	}
	int cur = 1;
	while(s.size() < n)
	{
		while(s.find(cur) != s.end())
		{
			cur++;
		}
		s.insert(cur);
	}
	int cnt = 0;
	for(set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cnt++;
		if(cnt > n) break;
		cout << (*it) << ' ';
	}
	*/
	int lo = 1; int hi = 1000000000;
	int ans = 0;
	while(lo <= hi)
	{
		int mid = (lo+hi)>>1;
		if(check(mid))
		{
			hi = mid - 1;
			ans = mid;
		}
		else
		{
			lo = mid + 1;
		}
		s.clear();
	}
	//cout << ans << '\n';
	construct(ans);
	int cur = 1;
	while(s.size() < n)
	{
		while(s.find(cur) != s.end())
		{
			cur++;
		}
		s.insert(cur);
	}
	int cnt = 0;
	for(set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cnt++;
		if(cnt > n) break;
		cout << (*it) << ' ';
	}
}