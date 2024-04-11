#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

inline int ran()
{
	static int x = 1;
	x += (x << 1) + 1;
	return x & 2147483647;
}
 
struct Node;
 
typedef pair <Node*, Node*> Pair;
 
Node *null;
 
struct Node
{
	int val, size, ans, tag, reverse;
	Node *left, *right;
	 
	Node (int val, int size, Node *left, Node *right) :
		val(val), size(size), left(left), right(right), ans(val), tag(0), reverse(0) {}
	 
	Node *Update()
	{
		size = left->size + 1 + right->size;
		ans = left->ans + val + right->ans;
		return this;
	}
	 
	void Add(int v) {
		if (this == null)
			return;
		ans += v, tag += v, val += v;
	}
	 
	void Reverse() {
		swap(left, right), reverse ^= 1;
	}
	 
	void Down() {
		if (tag != 0)
			left->Add(tag), right->Add(tag), tag = 0;
		if (reverse == 1)
			left->Reverse(), right->Reverse(), reverse = 0;
	}
	 
	Pair Split(int n);
};
 
Node *merge(Node *a, Node *b)
{
	if (a == null)
		return b;
	if (b == null)
		return a;
	if (ran() % (a->size + b->size) < a->size)
	{
		a->Down();
		a->right = merge(a->right, b);
		return a->Update();
	}
	 
	b->Down();
	b->left = merge(a, b->left);
	return b->Update();
}
 
Pair Node :: Split(int n)
{
	if (this == null)
		return make_pair(null, null);
	Down();
	if (left->size >= n)
	{
		Pair ret = left->Split(n);
		left = ret.second;
		return make_pair(ret.first, this->Update());
	}
	 
	Pair ret = right->Split(n - 1 - left->size);
	right = ret.first;
	return make_pair(this->Update(), ret.second);
}
 
Node *root;

int n, q;

int main() {
	scanf("%d %d", &n, &q);
	null = new Node(0, 0, null, null);
	root = null;
	for (int i = 1; i <= n; i++) {
		root = merge(root, new Node(1, 1, null, null));
	}
	
	while (q--) {
		int type, l, r;
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d", &l);
			if (l > n - l) {
				Pair ret = root->Split(l - (n - l));
				ret.first->Reverse();
				root = merge(ret.second, ret.first);
				l = n - l;
			}
			
			n -= l;
			Pair ret1 = root->Split(l);
			root = ret1.second;
			ret1.first->Reverse();
			Node *now = ret1.first;
			for (int i = 1; i <= l; i++) {
				ret1 = now->Split(1);
				Pair ret2 = root->Split(i - 1), ret3 = ret2.second->Split(1);
				ret3.first->Add(ret1.first->ans);
				root = merge(ret2.first, merge(ret3.first, ret3.second));
				now = ret1.second;
			}
		} else {
			scanf("%d %d", &l, &r);
			Pair ret1 = root->Split(l), ret2 = ret1.second->Split(r - l);
			printf("%d\n", ret2.first->ans);
			root = merge(ret1.first, merge(ret2.first, ret2.second));
		}
	}
	
	return 0;
}