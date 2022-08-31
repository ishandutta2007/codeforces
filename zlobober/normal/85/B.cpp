#include <iostream>
#include <memory.h>
#include <set>
using namespace std;

typedef long long llong;

const int N = 100500;

llong T[N];
int st[N];

llong c[3], tt[3];
	
llong curt = 0;

multiset<pair<llong, int> > W[3];
set<pair<llong, int> > ev;
int busy[3] = {0, 0, 0};
#define mp make_pair
		

void go(int q)
{
	if (q == -1 || q == 3 ||  busy[q] == c[q] || W[q].size() == 0)
		return;
	int nxt = W[q].begin()->second;
	W[q].erase(W[q].begin());
	busy[q]++;
	ev.insert(mp(curt + tt[q], nxt));
}

int main()
{
	memset(st, -1, sizeof(st));
	for (int i = 0; i < 3; i++)
		cin >> c[i];
	for (int i = 0; i < 3; i++)
		cin >> tt[i];
	int n;
	cin >> n;
	llong t;
	
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		T[i] = t;
		ev.insert(make_pair(t, i));
	}
	int q;
	int nxt;
	int s;
	llong ans = 0;
	while (!ev.empty())
	{
		t = ev.begin()->first;
		q = ev.begin()->second;
		//cerr << t << ' ' << q << endl;
		curt = t;
		ev.erase(ev.begin());

		if (st[q] != -1)
			busy[st[q]]--;
		go(st[q]);
		st[q]++;
		if (st[q] == 3)
		{
			ans = max(ans, t - T[q]);
			continue;
		}
		W[st[q]].insert(mp(T[q], q));
		go(st[q]);
	}
	cout << ans;
}