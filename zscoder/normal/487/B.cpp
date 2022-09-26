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

int a[100001];
int l[100001];
int r[100001];
int dp[100001];

map<int,int> S;

void ins(int x)
{
	S[x]++;
}

void del(int x)
{
	S[x]--; if(S[x]==0) S.erase(x);
}

int maxs()
{
	if(S.empty()) return -1;
	mit it = S.end();
	it--;
	return (*it).fi;
}

int mins()
{
	mit it = S.begin();
	return (*it).fi;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, s, d; cin >> n >> s >> d;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i] = 1000000000;
	}
	int ptr = 1;
	for(int i = 1; i <= n; i++)
	{
		ins(a[i]);
		while(ptr < i)
		{
			//cerr << i << ' ' << ptr << ' ' << maxs() - mins() << ' ' << S.size() << '\n';
			if(maxs() - mins() > s)
			{
				del(a[ptr]);
				ptr++;
			}
			else
			{
				break;
			}
		}
		l[i] = ptr;
		//cerr << "L : " << i << ' ' << l[i] << '\n';
	}
	S.clear();
	ptr = n;
	for(int i = n; i > 0; i--)
	{
		ins(a[i]);
		while(ptr > i)
		{
			if(maxs() - mins() > s)
			{
				del(a[ptr]);
				ptr--;
			}
			else
			{
				break;
			}
		}
		r[i] = ptr;
	}
	S.clear();
	dp[0] = 0;
	int pl = 0; int pr = 0;
	for(int i = 1; i <= n; i++)
	{
		int L = l[i] - 1; 
		int R = i - d;
		//cerr << L << ' ' << R << ' ' << pl << ' ' << pr << endl;
		if(R < L) continue;
		while(pr <= R)
		{
			ins(dp[pr]);
			pr++;
		}
		while(pl < L)
		{
			del(dp[pl]);
			pl++;
		}
		dp[i] = mins() + 1;
		//cerr << i << ' ' << dp[i] << '\n';
	}
	if(dp[n] >= 1000000000) dp[n] = -1;
	cout << dp[n];
}