# include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define sim template <class c
#define dor >debug & operator<< (
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug &>::type operator<< (c i) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c * x) -> decltype(cerr << *x, 2);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() {cerr << endl;}
eni(==) ris << range(begin(i), end(i));}
eni(!=) cerr << i; ris;}
sim dor rge<c> x) {
	cerr << "[";
	for (c it = x.b; it != x.e; ++it)
		*this << ", " + 2 * (x.b == it) << *it;
	ris << "]";
}
sim, class b dor pair <c,b> x) {ris << "(" << x.first << ", " << x.second << ")";}
#else
sim dor const c&) {ris;}
#endif
};
using ui = unsigned int;
using ll = long long;
struct mask {
	ui left, right;
	bool good;
	mask(ui _l = 0, ui _r = 0, bool g = true) : left(_l), right(_r), good(g) {}
};
debug & operator<<(debug & deb, mask m) {
	return deb << (m.good ? '+' : '-') << "[" << m.left << ", " << m.right << "]";
}
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) << ": " << a[i] << "] " 
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] " 
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "
void show(mask m) {
	for (int i = 24; i >= 0; i -= 8) {
		printf("%d", m.left >> i & 255);
		if (i)
			printf(".");
	}
	ui d = m.right - m.left;
	long long x = ((ll)d) + 1;
	int bits = 0;
	while (x != 1) {
		bits++;
		x /= 2;
	}
	printf("/%d\n", 32 - bits);
	debug << imie(m.left) imie(m.right) imie(m.good) imie(bits);
}
char in[100];
vector <mask> masks;
void err() {
	printf("-1\n");
	exit(0);
}
vector <mask> ans;
void go(ui low, ui high, vector <mask> masks) {
	debug << imask(low) imask(high) imie(masks);
	vector <mask> left, right;
	ui med = low + (high - low) / 2;
	bool whole_good = false, whole_bad = false, any_good = false, any_bad = false;
	for (auto m : masks) {
		if (m.left == low && m.right == high) {
			if (m.good) {
				whole_good = true;
				any_good = true;
			}
			else {
				whole_bad = true;
				any_bad = true;
			}
		}
		else {
			if (m.good)
				any_good = true;
			else
				any_bad = true;
			if (m.right <= med)
				left.push_back(m);
			else
				right.push_back(m);
		}
	}
	if (whole_good && any_bad) err();
	if (whole_bad && any_good) err();
	if (!any_bad)
		return;
	if (!any_good) {
		ans.push_back(mask(low, high, false));
		return;
	}
	go(low, med, left);
	go(med + 1, high, right);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", in);
		char type;
		ui a, b, c, d;
		int m;
		if (sscanf(in, " %c%d.%d.%d.%d/%d", &type, &a, &b, &c, &d, &m) != 6) {
			sscanf(in, " %c%d.%d.%d.%d", &type, &a, &b, &c, &d);
			m = 32;
		}
		mask Mask;
		ui ip = a << 24 | b << 16 | c << 8 | d;
		Mask.left = ip;
		Mask.right = ip + (1 << (32 - m)) - 1;
		Mask.good = (type == '+');
		masks.push_back(Mask);
	}
	go(0, ~0u, masks);
	printf("%d\n", (int)ans.size());
	for (auto m : ans)
		show(m);
}
/*
1
-149.154.167.99

1
0.0.0.0/0
4
-149.154.167.99
+149.154.167.100/30
+149.154.167.128/25
-149.154.167.120/29

2
149.154.167.96/30
149.154.167.112/28
5
-127.0.0.4/31
+127.0.0.8
+127.0.0.0/30
-195.82.146.208/29
-127.0.0.6/31

2
127.0.0.4/30
128.0.0.0/1
2
+127.0.0.1/32
-127.0.0.1

-1
1
-149.154.167.99

1
0.0.0.0/0

4
-149.154.167.99
+149.154.167.100/30
+149.154.167.128/25
-149.154.167.120/29

2
149.154.167.96/30
149.154.167.112/28

5
-127.0.0.4/31
+127.0.0.8
+127.0.0.0/30
-195.82.146.208/29
-127.0.0.6/31

2
127.0.0.4/30
128.0.0.0/1

2
+127.0.0.1/32
-127.0.0.1

-1

*/