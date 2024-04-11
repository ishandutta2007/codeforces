#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
namespace treap {
	struct node {
		int prior, sz, dp, add;
		node *l, *r;
		node(int x) {
			prior = (rand() << 15) | rand();
			// sz = 1;
			dp = x;
			l = r = NULL;
			add = 0;
		}
	};

	typedef node * pnode;

	void push(node* T) {
		T->dp += T->add;
		if (T->l)
			T->l->add += T->add;
		if (T->r)
			T->r->add += T->add;
		T->add = 0;
	}

	node* merge(node * L, node * R) {
		if (!L) {
			return R;
		}
		if (!R) {
			return L;
		}
		if (L->prior > R->prior) {
			push(L);
			L->r = merge(L->r, R);
			return L;
		}
		push(R);
		R->l = merge(L, R->l);
		return R;
	}

	pair<node*,node*> split(pnode T, int value) {
		if (!T) {
			return make_pair(nullptr,nullptr);
		}
		push(T);
		if (T->dp >= value) {
			auto p=split(T->l, value);
			T->l=p.second;
			return make_pair(p.first,T);
		}
		else {

			auto p = split(T->r, value);
			T->r = p.first;
			return make_pair(T, p.second);
		}
	}

	int findBegin(pnode T) {
		push(T);
		if (!T->l)
			return T->dp;
		return findBegin(T->l);
	}

	int findMax(pnode T, int n) {
		if (!T)
			return 0;
		push(T);
		return findMax(T->l, n) + findMax(T->r, n) + (T->dp <= 1e9 ? 1 : 0);
	}


}
#include<random>


int main() {
	using namespace treap;
	int Q; cin >> Q;
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_real_distribution<> rand1(0, 1);
	node* T = new node(0);
	for (int i = 0; i <= Q; ++i) {

		T = merge(T, new node(1e9 + i));
	}
	for (int q = 0; q<Q; ++q) {
		int l, r; scanf("%d %d", &l, &r);
		auto p=split(T, l);
		auto L=p.first;
		auto R=p.second;
		auto pp=split(R, r);
		auto  M=pp.first;
		R=pp.second;
		if (M)
			M->add += 1;
		int cnt = findBegin(R);
		auto ppp=split(R, cnt + 1);
		R=ppp.second;
		T = merge(L, new node(l));
		T = merge(T, M);
		T = merge(T, R);

	}

	printf("%d\n", findMax(T, Q) - 1);
	return 0;
}