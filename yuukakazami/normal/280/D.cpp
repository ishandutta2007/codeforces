#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const int MAX_N = 100000 + 10;

int a[MAX_N];
int n, maxOpt;

struct Segment {
	int l, r, sum; //[l,r)
	Segment(int l = 0, int r = 0, int sum = 0) :
			l(l), r(r), sum(sum) {
	}
	Segment(const Segment&a, const Segment&b) {
		l = a.l, r = b.r;
		sum = a.sum + b.sum;
	}
	bool operator<(const Segment&o) const {
		return sum < o.sum;
	}
};

void updateMax(Segment&ret, const Segment&a, const Segment&b) { //update max
	if (a.sum + b.sum > ret.sum) {
		ret.sum = a.sum + b.sum;
		ret.l = a.l, ret.r = b.r;
	}
}

void updateMin(Segment&ret, const Segment&a, const Segment&b) { //update min
	if (a.sum + b.sum < ret.sum) {
		ret.sum = a.sum + b.sum;
		ret.l = a.l, ret.r = b.r;
	}
}

struct Data {
	Segment sum;
	Segment maxL, maxR, maxS;
	Segment minL, minR, minS;
	bool ok;

	Data(bool v = true) :
			ok(v) {
	}

	Data(int l, int r, int v) :
			ok(true) {
		sum = Segment(l, r, v);

		Segment eL = Segment(l, l, 0), eR = Segment(r, r, 0);

		if (v > 0)
			maxL = maxR = maxS = sum;
		else
			maxL = eL, maxR = eR, maxS = eL;

		if (v < 0)
			minL = minR = minS = sum;
		else
			minL = eL, minR = eR, minS = eL;
	}

	void doit(Segment&mi, Segment&mx) {
		mi.sum *= -1;
		mx.sum *= -1;
		swap(mi, mx);
	}

	void applyNegative() {
		sum.sum *= -1;
		doit(maxL, minL);
		doit(maxR, minR);
		doit(maxS, minS);
	}
};

const Data BAD(false);

Data operator+(const Data&L, const Data&R) {
	if (!L.ok)
		return R;
	if (!R.ok)
		return L;
	Data ret;
	ret.sum = Segment(L.sum, R.sum);

	ret.maxL = L.maxL;
	updateMax(ret.maxL, L.sum, R.maxL);

	ret.maxR = R.maxR;
	updateMax(ret.maxR, L.maxR, R.sum);

	ret.maxS = max(L.maxS, R.maxS);
	updateMax(ret.maxS, L.maxR, R.maxL);

	ret.minL = L.minL;
	updateMin(ret.minL, L.sum, R.minL);

	ret.minR = R.minR;
	updateMin(ret.minR, L.minR, R.sum);

	ret.minS = min(L.minS, R.minS);
	updateMin(ret.minS, L.minR, R.minL);

	return ret;
}

struct Tree {
	Data data;
	Tree*pl, *pr;
	int l, r;

	bool negative;

	void update() {
		data = pl->data + pr->data;
	}

	Tree(int l, int r) :
			l(l), r(r), negative(false) {
		if (l + 1 == r) {
			data = Data(l, r, a[l]);
			return;
		}
		pl = new Tree(l, (l + r) >> 1);
		pr = new Tree((l + r) >> 1, r);
		update();
	}

	void applyNegative() {
		negative ^= 1;
		data.applyNegative();
	}

	void relax() {
		if (negative) {
			negative = false;
			pl->applyNegative();
			pr->applyNegative();
			return;
		}
	}

	Data calc(int L, int R) {
		if (L <= l && R >= r)
			return data;
		if (L >= r || l >= R)
			return BAD;
		relax();
		return pl->calc(L, R) + pr->calc(L, R);
	}

	void change(int i, int v) {
		if (i < l || i >= r)
			return;
		if (l + 1 == r) {
			data = Data(l, r, v);
			return;
		}
		relax();
		pl->change(i, v);
		pr->change(i, v);
		update();
		return;
	}

	void makeNegative(int L, int R) {
		if (L <= l && R >= r) {
			applyNegative();
			return;
		}

		if (L >= r || l >= R)
			return;

		relax();
		pl->makeNegative(L, R);
		pr->makeNegative(L, R);
		update();
	}
};

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	Tree*root = new Tree(0, n);
	scanf("%d", &maxOpt);
	for (int it = 0; it < maxOpt; ++it) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int i, v;
			scanf("%d%d", &i, &v);
			--i;
			a[i] = v;
			root->change(i, v);
		} else {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			--l;
			Segment ret[20];
			int cnt = 0;

			int ans = 0;

//			cout << "show:";
//			for (int j = l; j < r; ++j) {
//				cout << a[j] << " ";
//			}
//			cout << endl;

			for (int j = 0; j < k; ++j) {
				Segment det = root->calc(l, r).maxS;
				if (det.sum <= 0)
					break;
//				cout << det.l << " " << det.r << " " << det.sum << endl;
				ans += det.sum;
				ret[cnt++] = det;
				root->makeNegative(det.l, det.r);
			}

			//go back
			for (int j = 0; j < cnt; ++j) {
				root->makeNegative(ret[j].l, ret[j].r);
			}

			printf("%d\n", ans);
		}
	}
}