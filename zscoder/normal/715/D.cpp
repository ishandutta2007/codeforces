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

typedef pair<ii,ii> move;

set<move> ans;
int curx, cury;

bool isvalid(move x)
{
	if(x.fi.fi > 0 && x.se.fi > 0 && x.fi.se > 0 && x.se.se > 0 && x.fi.fi <= curx && x.fi.se <= cury && x.se.fi <= curx && x.se.se <= cury) return true;
	return false;
}

void edge(int x1, int y1, int x2, int y2)
{
	ans.insert(mp(mp(x1, y1), mp(x2, y2)));
}

void add(int bit)
{
	int x = curx;
	edge(x,x+2,x,x+3);
	edge(x+1,x+2,x+1,x+3);
	edge(x+2,x,x+3,x);
	edge(x+2,x+1,x+3,x+1);
	edge(x-2,x+3,x-1,x+3);
	edge(x,x+4,x+1,x+4);
	edge(x+3,x-2,x+3,x-1);
	edge(x+4,x,x+4,x+1);
	edge(x-1,x+1,x,x+1);
	if(bit%3==0) edge(x-1,x+2,x,x+2);
	if(bit%3!=2) edge(x+2,x-1,x+2,x);
	if(bit<3) edge(x+1,x-1,x+1,x);
	curx += 2; cury += 2;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t; cin >> t;
	vector<int> digits;
	while(t)
	{
		digits.pb(t%6);
		t/=6;
	}
	reverse(digits.begin(), digits.end());
	edge(1, 2, 2, 2);
	edge(2, 1, 2, 2);
	curx = 2; cury = 2;
	for(int i = 0; i < digits.size(); i++)
	{
		add(digits[i]);
	}
	cout << curx << ' ' << cury << '\n';
	vector<move> clr;
	for(set<move>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		if(!isvalid(*it))
		{
			clr.pb(*it);
		}
	}
	for(int i = 0; i < clr.size(); i++)
	{
		ans.erase(clr[i]);
	}
	cout << ans.size() << '\n';
	for(set<move>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		move tmp = (*it);
		cout << tmp.fi.fi << ' ' << tmp.fi.se << ' ' << tmp.se.fi << ' ' << tmp.se.se << '\n';
	}
}