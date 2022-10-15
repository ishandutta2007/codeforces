#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
#define p_siz(x) tr[x].p_siz
#define siz(x) tr[x].siz
#define rev(x) tr[x].rev
#define mx(x) tr[x].mx
#define ch(x, p) tr[x].ch[p]
#define fa(x) tr[x].fa
#define val(x) tr[x].val
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m;

struct Node {
	int p_siz, siz, rev, mx, fa, val, ch[2];
} tr[kN];
int Pos(int x) { return x == ch(fa(x), 1); }
int IsRoot(int x) { return !x || (x != ch(fa(x), 0) && x != ch(fa(x), 1)); }
void Update(int x) {
	p_siz(x) = p_siz(ch(x, 0)) + p_siz(ch(x, 1)) + siz(x) + (x <= n);
	mx(x) = val(mx(ch(x, 0))) > val(mx(ch(x, 1))) ? mx(ch(x, 0)) : mx(ch(x, 1));
	if(val(x) > val(mx(x))) mx(x) = x;
}
void PushTag(int x) {
	if(rev(x)) {
		rev(x) ^= 1;
		rev(ch(x, 0)) ^= 1; rev(ch(x, 1)) ^= 1;
		std::swap(ch(ch(x, 0), 0), ch(ch(x, 0), 1));
		std::swap(ch(ch(x, 1), 0), ch(ch(x, 1), 1));
	}
}
void ClearTag(int x) {
	if(!IsRoot(x)) ClearTag(fa(x));
	PushTag(x);
}
void Rotate(int x) {
	int y = fa(x), z = fa(y), p = Pos(x);
	if(!IsRoot(y)) ch(z, Pos(y)) = x;
	fa(x) = z; fa(y) = x; fa(ch(x, p ^ 1)) = y;
	ch(y, p) = ch(x, p ^ 1); ch(x, p ^ 1) = y;
	Update(y); Update(x);
}
void Splay(int x) {
	ClearTag(x);
	for(; !IsRoot(x); Rotate(x))
		if(!IsRoot(fa(x))) Rotate(Pos(fa(x)) == Pos(x) ? fa(x) : x);
}
int Access(int x) {
	int p = 0;
	for(; x; p = x, x = fa(x)) {
		Splay(x);
		siz(x) += p_siz(ch(x, 1)) - p_siz(p);
		ch(x, 1) = p; Update(x);
	}
	return p;
}
void MakeRoot(int x) {
	rev(x = Access(x)) ^= 1;
	std::swap(ch(x, 0), ch(x, 1));
}
int Find(int x) {
	Access(x); Splay(x);
	for(; ch(x, 0); x = ch(x, 0)) PushTag(x);
	Splay(x);
	return x;
}
void Split(int x, int y) {
	MakeRoot(x); Access(y); Splay(y);
}
void Cut(int x, int y) {
	Split(x, y); ch(y, 0) = fa(x) = 0; Update(y);
}
void Link(int x, int y) {
	MakeRoot(x); Splay(x); fa(x) = y;
	siz(y) += p_siz(x); p_siz(y) += p_siz(x);
}

struct Edge {
	int u, v, w;
} E[kN];
struct Cmp {
	bool operator ()(const int &x, const int &y) {
		return E[x].w < E[y].w;
	}
};
std::priority_queue <int, std::vector <int>, Cmp> pq;
bool vis[kN];
void Adjust() {
	while(!pq.empty()) {
		int t = pq.top(), u = E[t].u, v = E[t].v, w = E[t].w;
		if(!vis[t]) { pq.pop(); continue; }
		Cut(u, t + n); Cut(v, t + n);
		if(p_siz(Find(u)) & p_siz(Find(v)) & 1) {
			Link(u, t + n); Link(v, t + n);
			break;
		} else {
			pq.pop();
			vis[t] = false;
		}
	}
}
void Calc() {
	int tot = n;
	for(int i = 1; i <= m; ++i) {
		int u = E[i].u, v = E[i].v, w = E[i].w, f_u = Find(u), f_v = Find(v);
		if(f_u != f_v) {
			int s_u = p_siz(f_u), s_v = p_siz(f_v);
			if(s_u & s_v & 1) tot -= 2;
			Link(u, i + n); Link(v, i + n);
			pq.push(i); vis[i] = true;
		} else {
			Split(u, v);
			int p = mx(v) - n;
			if(E[p].w > w) {
				Cut(E[p].u, p + n); Cut(E[p].v, p + n);
				Link(u, i + n); Link(v, i + n);
				pq.push(i); vis[i] = true;
				vis[p] = false;
			}
		}
		if(!tot) Adjust();
		if(tot) printf("-1\n");
		else printf("%d\n", E[pq.top()].w);
	}
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= m; ++i) {
			rd(E[i].u, E[i].v, E[i].w);
			val(i + n) = E[i].w;
		}
		Calc();
	} return 0;
}