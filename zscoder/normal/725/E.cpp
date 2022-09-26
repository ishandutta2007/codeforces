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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int cnt[200001];
const int C = 200000;
pbds tmp;

int nt(int n, int c)
{
	if(c <= 0) return -1;
	c = min(n, c);
	int l = tmp.order_of_key(c+1);
	if(l == 0) return -1;
	//cerr<<l<<'\n';
	return *(tmp.find_by_order(l-1));
}

bool ok(ll n, int c)
{
	//cerr<<n<<' '<<c<<'\n';
	if(n == 0) return 1;
	if(c < 0) return 0;
	if(cnt[c] > 0)
	{
		if(ll(cnt[c])*ll(c) < ll(n))
		{
			n -= ll(cnt[c])*ll(c);
			return ok(n, nt(n, c-1));
		}
		else
		{
			n%=c;
			if(n == 0) return 1;
			return ok(n, nt(n, c-1));
		}
	}
	else
	{
		return ok(n, nt(n, c-1));
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int c; cin>>c;
	int n; cin>>n;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		cnt[x]++; tmp.insert(x);
	}
	for(int i = 1; i < c; i++)
	{
		cnt[i]++;
		if(cnt[i] == 1)
		{
			tmp.insert(i);
		}
		//cerr<<i<<'\n';
		if(!ok(c, c + 1))
		{
			cout << i;
			return 0;
		}
		cnt[i]--;
		if(cnt[i] == 0)
		{
			tmp.erase(i);
		}
	}
	cout << "Greed is good";
}