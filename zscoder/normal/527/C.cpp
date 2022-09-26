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

pbds x, y;
map<int,int> a, b;

void dela(int x)
{
	a[x]--; if(a[x]==0){a.erase(x);}
}

void insa(int x)
{
	a[x]++;
}

void delb(int x)
{
	b[x]--; if(b[x]==0){b.erase(x);}
}

void insb(int x)
{
	b[x]++;
}

ll ask()
{
	mit it = a.end(); it--;
	ll ans = (*it).fi;
	it = b.end(); it--;
	ans *= (*it).fi;
	return ans;
}

int findlower(pbds &t, int x)
{
	int cur = t.order_of_key(x);
	cur--;
	return (*t.find_by_order(cur));
}

int findupper(pbds &t, int x)
{
	int cur = t.order_of_key(x);
	return (*t.find_by_order(cur));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h, w, n; cin >> h >> w >> n;
	x.insert(0); x.insert(h);
	y.insert(0); y.insert(w);
	insa(h); insb(w);
	for(int i = 0; i < n; i++)
	{
		char c; int z;
		cin >> c >> z;
		if(c == 'H') //y
		{
			int l = findlower(y, z); int r = findupper(y, z);
			y.insert(z);
			delb(r-l); insb(z-l); insb(r-z);
		}
		else
		{
			int l = findlower(x, z); int r = findupper(x, z);
			x.insert(z);
			dela(r-l); insa(z-l); insa(r-z);
		}
		cout << ask() << '\n';
	}	
}