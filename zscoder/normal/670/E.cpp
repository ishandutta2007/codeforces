#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int pa[500001];

int n, m, p;
class dsu
{
	private:
	vi pare; vi h; vi nxt; int num;
	public:
	dsu(int n)
	{
		pare.assign(n, 0);
		nxt.assign(n, 0);
		for(int i = 0; i < n; i++) {pare[i] = nxt[i] = i;}
		h.assign(n, 0);
		num = n;	
	}
	int root(int i) { return pare[i] == i ? i : pare[i] = root(pare[i]); }
    int head(int i) {return nxt[root(i)]; }
	void unionSet(int i, int j) {
        if ((i = root(i)) == (j = root(j))) return;
 
        int pos = nxt[root(j)];
 
        num--;
        if (h[i] > h[j])
            pare[j] = i, nxt[i] = pos;
        else
            pare[i] = j, h[j] += (h[i] == h[j]);
    }
};
/*
int parent[500001];
int parent2[500001];

void make_set (int v) {
	parent[v] = v;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}

void init() {
	for (int i=0; i<=n+1; ++i)
		make_set (i);
}
 
void process_query (int l, int r) {
	for (int v=l; ; ) {
		v = find_set (v);
		if (v > r)  break;
		parent[v] = v+1;
	}
}

void make_set2 (int v) {
	parent2[v] = v;
}
 
int find_set2 (int v) {
	if (v == parent2[v]) return v;
	return parent2[v] = find_set2(parent2[v]);
}

void init2() {
	for (int i=0; i<=n+1; ++i)
		make_set2(i);
}
 
void process_query2 (int l, int r) {
	for (int v=r; ; ) {
		v = find_set2(v);
		if (v < l)  break;
		parent2[v] = v-1;
	}
}
*/
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> p;
	string bracket;
	string command;
	cin >> bracket;
	cin >> command;
	/*
	l[0] = 0; r[n + 1] = n + 1;
	for(int i = 1; i <= n; i++)
	{
		l[i] = i;
		r[i] = i;
	}
	*/
	dsu dl(n+2);
	dsu dr(n+2);
	//init(); init2();
	stack<pair<char,int> > s;
	for(int i = 0; i < n; i++)
	{
		if(!s.empty() && bracket[i] != s.top().fi)
		{
			pa[i + 1] = s.top().se;
			pa[s.top().se] = i + 1;
			s.pop();
		}
		else
		{
			s.push(mp(bracket[i], i + 1));
		}
	}
	int ptr = p;
	for(int i = 0; i < m; i++)
	{
		//cout << ptr << endl;
		char c = command[i];
		if(c == 'L')
		{
			ptr = dl.head(ptr-1);
		}
		else if(c == 'R')
		{
			ptr = dr.head(ptr+1);
		}
		else
		{
			int L, R;
			L = ptr; R = pa[ptr];
			
			if(L > R) swap(L, R);
			//cout << L << ' ' << R << endl;
			//process_query(L, R);
			//process_query2(L, R);
			int l, r;
			l = L; r = R;
			while(l <= r)
			{
				if(dr.head(l) == l) {dr.unionSet(l, l+1); l++;}
				else l = dr.head(l);
			}
			l = L; r = R;
			while(l <= r)
			{
				if(dl.head(r) == r) {dl.unionSet(r, r-1); r--;}
				else r = dl.head(r);
			}
			ptr = dr.head(R + 1);
			if(ptr > n) ptr = dl.head(L - 1);
			//r[L] = r[R + 1];
			//l[R] = l[L - 1];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		//cout << i << ' ' << find_set(i) << ' ' << find_set2(i) << endl;
		//if(find_set(i) == i && find_set2(i) == i)
		if(dl.head(i) == i && dr.head(i) == i)
		{
			cout << bracket[i-1];
		}
	}
	return 0;
}