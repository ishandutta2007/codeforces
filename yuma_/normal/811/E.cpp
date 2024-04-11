#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;

#define Seg_Max_N (1<<17) 
int H,W;
vector<vector<int>>field;

struct line {
	int answer;
	int l_v,r_v;
	vector<int>ls,rs;
	line() {
		answer=-1;
	}
	void un(int x, int y) {
		answer--;
		for (int i = 0; i < H; ++i) {
			if(ls[i]==x)ls[i]=y;
			if(rs[i]==x)rs[i]=y;
		}
	}
};
using Value = line;
Value ini;
struct segtree {
	int N;
	vector<Value>dat;

	segtree() {}
	segtree(int n) :dat(2 * Seg_Max_N) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ini;
		}
	}
	Value connect( Value&l,  Value&r) {
		if(l.answer==-1)return r;
		else if(r.answer==-1)return l;
		else {
			int sum=l.answer+r.answer;
			
			Value v;
			v.answer=l.answer+r.answer;
			v.l_v=l.l_v;
			v.r_v=r.r_v;
			v.ls=l.ls;
			v.rs=r.rs;
			for (int i = 0; i < H; ++i) {
				if (field[i][l.r_v - 1] == field[i][r.l_v]) {
					if (l.rs[i] != r.ls[i]) {
						v.un(l.rs[i],r.ls[i]);
						l.un(l.rs[i],r.ls[i]);
					}
				}
			}

			return v;
		}
	}
	// update k th element
	void update(int k, Value a) {
		k += N - 1;
		dat[k] = a;

		while (k > 0) {
			k = (k - 1) / 2;
			Value al(dat[k * 2 + 1]);
			Value ar(dat[k * 2 + 2]);
			dat[k] = connect(al, ar);
		}
	}
	// min [a, b)
	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
	Value  query(int a, int b, int k, int l, int r) {
		if (r <= a or b <= l) return ini;
		if (a <= l and r <= b) return dat[k];
		const int m = (l + r) / 2;
		 Value al(query(a, b, k * 2 + 1, l, m));
		 Value ar(query(a, b, k * 2 + 2, m, r));
		return connect(al, ar);
	}
};

int main() {

	int Q;cin>>H>>W>>Q;
	ini = line{};
	field=vector<vector<int>>(H,vector<int>(W));
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			scanf("%d",&field[y][x]);
		}
	}
	segtree seg(W);
	for (int i = 0; i < W; ++i) {
		line lin;
		lin.answer=H;
		lin.l_v=i;
		lin.r_v=i+1;
		vector<int>k(H);
		iota(k.begin(),k.end(),i*H);
		lin.ls=k;
		lin.rs=k;
		for (int y = 0; y < H - 1; ++y) {
			if (field[y][i] == field[y + 1][i]) {
				lin.un(i*H+y,i*H+y+1);
			}
		}
		seg.update(i, lin);
	}
	while (Q--) {
		int l,r;
		scanf("%d %d",&l,&r);
		l--;
		auto p=seg.query(l,r);
		printf("%d\n",p.answer);
	}
	return 0;
}