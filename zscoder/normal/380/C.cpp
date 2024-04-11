#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
string s;
int n;
struct node
{
	int a, o, c;
};

node emp;

node st[4000001];

node add(node x, node y)
{
	node z;
	z.a = x.a + y.a + min(x.o - x.a, y.c - y.a);
	z.c = x.c + y.c;
	z.o = x.o + y.o;
	return z;
}
void build(int id = 1, int l = 0, int r = n)
{
	if(r - l < 2)
	{
		st[id].a = 0;
		if(s[l] == '(') st[id].o = 1;
		else st[id].c = 1;
		return ;
	}
	int mid = (l+r)>>1;
	build(2*id, l, mid);
	build(2*id+1, mid, r);
	st[id] = add(st[2*id], st[2*id + 1]);
}

node query(int id, int x, int y, int l, int r)
{
	//cout << id << " " << st[id].a << ' ' << st[id].o << ' ' << st[id].c << ' ' << x << ' ' << y << ' ' << l << ' ' << r << '\n';
	if(x >= r || y <= l) return emp;
	if(l >= x && r <= y) return st[id];
	int mid = (l+r)>>1;
	return add(query(id*2, x, y, l, mid), query(id*2 + 1, x, y, mid, r));
}

int main()
{
	//freopen("Sereja and Brackets.in", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	emp.a = 0; emp.c = 0; emp.o = 0;
	cin >> s; n = s.length();
	int q; cin >> q;
	build();
	for(int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y; x--;
		cout << 2*query(1, x, y, 0, n).a << "\n";
	}
	return 0;
}