#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define INF ((int) 1e9+10)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define MOD 60

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int N;
int arr[100000];
int Q;

struct stree
{
	int l, r;
	char f[MOD];
	int ttk[MOD];
	stree *left, *right;

	stree(int a, int b)
	{
		l = a; r = b;
		if (a == b)
		{
			left = right = NULL;
			upd(arr[a]);
		}
		else
		{
			int mid = (a + b) / 2;
			left = new stree(a, mid);
			right = new stree(mid+1, b);
			combine();
		}
	}

	void upd(int x)
	{
		ji(MOD)
		{
			f[i] = i % x == 0 ? i+2 : i+1;
			f[i] %= MOD;
			ttk[i] = i % x == 0 ? 2 : 1;
		}
	}

	void combine()
	{
		ji(MOD)
		{
			f[i] = right->f[left->f[i]];
			ttk[i] = left->ttk[i] + right->ttk[left->f[i]];
		}
	}

	void update(int pos, int val)
	{
		if (pos < l || pos > r)
			return;
		if (l == r)
			upd(val);
		else
		{
			left->update(pos, val);
			right->update(pos, val);
			combine();
		}
	}

	pair<char, int> query(int a, int b, char c)
	{
		if (a <= l && b >= r)
			return mp(f[c], ttk[c]);
		if (b < l || a > r)
			return mp(c, 0);
		pair<char, int> p1 = left->query(a, b, c);
		pair<char, int> p2 = right->query(a, b, p1.first);
		return mp(p2.first, p1.second + p2.second);
	}
};

int main()
{
	rint(N); ji(N) rint(arr[i]);
	stree root(0, N-1);

	rint(Q);
	jk(Q)
	{
		char buf[2];
		scanf("%s", buf);
		int a, b;
		rint(a); rint(b);

		if (*buf == 'A')
		{
			printf("%d\n", root.query(a-1, b-2, 0).second);
		}
		else
		{
			root.update(a-1, b);
		}
	}
}