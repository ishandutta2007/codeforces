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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int LG = 31;
map<int,int> ma;

struct node
{
	int g[2]; int siz;
};

vector<node> tre;
node emp;
int cnt = 0;

void insert(int x)
{
	int pos = 0;
	for(int i = LG - 1; i >= 0; i--)
	{
		int dig = 0;
		if(x&(1<<i)) dig = 1;
		//cout << dig;
		tre[pos].siz++;
		if(tre[pos].g[dig] == -1)
		{
			tre.pb(emp);
			tre[pos].g[dig] = cnt;
			pos = cnt;
			cnt++;
		}
		else
		{
			pos = tre[pos].g[dig];
		}
	}
	tre[pos].siz++;
	//cout << '\n';
}

void rem(int x)
{
	int pos = 0;
	tre[0].siz--;
	for(int i = LG - 1; i >= 0; i--)
	{
		int dig = 0;
		if(x&(1<<i)) dig = 1;
		int nxt = tre[pos].g[dig];
		if(nxt == -1) return ;
		//cout << nxt << ' ' << tre[nxt].siz << '\n';
		tre[nxt].siz--;
		int sz = tre[nxt].siz;
		if(sz == 0)
		{
			tre[pos].g[dig] = -1;
			return ;
		}
		pos = nxt;
	}
	//cout << '\n';
}

void add(int x)
{
	ma[x]++;
	if(ma[x] == 1) insert(x);
}

void del(int x)
{
	ma[x]--;
	if(ma[x] == 0) rem(x);
}

int query(int x)
{
	int pos = 0;
	int ans = 0; 
	for(int i = LG - 1; i >= 0; i--)
	{
		int dig = 0;
		if(x&(1<<i)) dig = 1;
		int nxt = tre[pos].g[(dig^1)];
		if(nxt == -1)
		{
			//cout << dig;
			nxt = tre[pos].g[dig];
			if(nxt == -1) continue ;
			pos = nxt;
			ans += dig*(1<<i);
			continue ;
		}
		else
		{
			//cout << (dig^1);
			pos = nxt;
			ans += (dig^1)*(1<<i);
			continue ;
		}
	}
	//cout<< '\n';
	return (ans^x);
}	

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	emp.g[0] = -1; emp.g[1] = -1; emp.siz = 0;
	tre.pb(emp); cnt++;
	insert(0); ma[0]++;
	int q; cin >> q;
	for(int i = 0; i < q; i++)
	{
		char c; cin >> c; int x; cin >> x;
		if(c == '+')
		{
			add(x);
		}
		else if(c == '-')
		{
			del(x);
		}
		else
		{
			cout << query(x) << '\n';
		}
	}
	return 0;
}