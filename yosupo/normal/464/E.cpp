#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef unsigned int uint;


const int MN = 110000;

const ll HMD[4] = {
	597749437,
	866176429,
	907592663,
	879117227,
};
ll HMDB[4];
ll PM[4][MN];
void pminit() {
	mt19937 mt(time(NULL));
	for (int i = 0; i < 4; i++) {
		uniform_int_distribution<> r(0, HMD[i]);
		HMDB[i] = r(mt);
	}
	for (int i = 0; i < 4; i++) {
		PM[i][0] = 1;
		for (int j = 1; j < MN; j++) {
			PM[i][j] = PM[i][j-1]*HMDB[i] % HMD[i];
		}
	}
}


struct Tree {

    struct Node {
        Node *l, *r;
        int sz;
       	uint d;
       	ll hash[4];
        Node(int li, int ri) {
            sz = ri-li;
            d = 0;
            if (ri-li == 1) return;
            int md = (li+ri)/2;
            l = new Node(li, md);
            r = new Node(md, ri);
        }
    } *n;

    typedef Node* NP;

    Tree() {
        n = NULL;
    }
    Tree(NP u) {
        n = new Node(*u);
    }
    Tree(int li, int ri) {
        n = new Node(li, ri);
    }

    static pair<NP, bool> add(NP x, int k) {
    	x = new Node(*x);
    	if (x->sz == 1) {
    		x->d += 1;
    		fill_n(x->hash, 4, x->d);
    		x->d %= 2;
    		return {x, !x->d};
    	}
    	bool f = true, res = false;
    	if (k < x->l->sz) {
    		auto u = add(x->l, k);
    		x->l = u.first;
    		f &= u.second;
    	}
    	if (f) {
    		k = max(k, x->l->sz);
    		auto u = add(x->r, k - x->l->sz);
    		x->r = u.first;
    		res |= u.second;
    	}
    	for (int i = 0; i < 4; i++) {
    		x->hash[i] = (x->l->hash[i] + x->r->hash[i] * PM[i][x->l->sz]) % HMD[i];
    	}
    	return {x, res};
    }
    static bool equal(NP l, NP r) {
    	assert(l->sz == r->sz);
    	if (l->sz == 1) {
    		return l->d == r->d;
    	}
    	bool f = true;
    	for (int i = 0; i < 4; i++) {
    		if (l->hash[i] != r->hash[i]) {
    			f = false;
    		}
    	}
    	if (f) return true;
    	return equal(l->l, r->l) && equal(l->r, r->r);
    }
    static bool comp(NP l, NP r) {
    	assert(l->sz == r->sz);
    	if (l->sz == 1) {
    		return l->d < r->d;
    	}
    	if (!equal(l->r, r->r)) {
    		return comp(l->r, r->r);
    	}
    	return comp(l->l, r->l);
    }
    static void print(NP x) {
    	if (x->sz == 1) {
    		printf("%d", x->d);
    		return;
    	}
    	print(x->l);
    	print(x->r);
    }
    Tree add(int k) {
    	return Tree(add(n, k).first);
    }
    void print() {
    	print(n);
    }
    bool operator<(const Tree &l) const {
    	return comp(n, l.n);
    }
};

const ll MD = 1e9+7;


typedef pair<int, int> E;
typedef tuple<Tree, int, int> P;

vector<E> g[MN];
map<E, int> gm;
int back[MN];
bool used[MN];

ll pw2[MN];

int main() {
	pminit();
	pw2[0] = 1;
	for (int i = 1; i < MN; i++) {
		pw2[i] = pw2[i-1]*2 % MD;
	}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, x;
		cin >> a >> b >> x; a--; b--;
		g[a].push_back(E(b, x));
		g[b].push_back(E(a, x));
		gm[E(a, b)] = x;
		gm[E(b, a)] = x;
	}
	int s, t;
	cin >> s >> t; s--; t--;
	priority_queue<P, vector<P>, greater<P>> q;
	Tree t1 = Tree(0, MN);
	Tree t2 = t1.add(2);
	q.push(P(Tree(0, MN), s, -1));
	while (!q.empty()) {
		int a, b; Tree t;
		tie(t, a, b) = q.top(); q.pop();
		if (used[a]) continue;
		used[a] = true;
		back[a] = b;
		for (E e: g[a]) {
			if (used[e.first]) continue;
			q.push(P(t.add(e.second), e.first, a));
		}
	}
	vector<int> v;
	if (!used[t]) {
		printf("-1\n");
		return 0;
	}
	while (s != t) {
		v.push_back(t);
		t = back[t];
	}
	v.push_back(s);
	reverse(v.begin(), v.end());
	ll res = 0;
	for (int i = 0; i < v.size()-1; i++) {
		res += pw2[gm[E(v[i], v[i+1])]];
		res %= MD;
	}
	cout << res << endl;
	cout << v.size() << endl;
	for (int d: v) {
		cout << d+1 << " ";
	}
	cout << endl;
    return 0;
}