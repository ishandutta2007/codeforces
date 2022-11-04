#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

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
	int val, size, v2;
	long long ans;
	Node *left, *right;
	 
	Node (int val, int v2, int size, Node *left, Node *right) : val(val), v2(v2), size(size), left(left), right(right), ans(val) {}
	 
	Node *Update()
	{
		size = left->size + 1 + right->size;
		ans = left->ans + val + right->ans;
		return this;
	}
	 
	Pair Split(double x);
	Pair Split(int x, int y);
};
 
Node *Merge(Node *a, Node *b)
{
	if (a == null)
		return b;
	if (b == null)
		return a;
	if (ran() % (a->size + b->size) < a->size)
	{
		a->right = Merge(a->right, b);
		return a->Update();
	}
	 
	b->left = Merge(a, b->left);
	return b->Update();
}
 
Pair Node :: Split(double x)
{
	if (this == null)
		return make_pair(null, null);
	if ((double)val > x)
	{
		Pair ret = left->Split(x);
		left = ret.second;
		return make_pair(ret.first, this->Update());
	}
	 
	Pair ret = right->Split(x);
	right = ret.first;
	return make_pair(this->Update(), ret.second);
}

Pair Node :: Split(int x, int y)
{
	if (this == null)
		return make_pair(null, null);
	if (val > x || (val == x && v2 > y))
	{
		Pair ret = left->Split(x, y);
		left = ret.second;
		return make_pair(ret.first, this->Update());
	}
	 
	Pair ret = right->Split(x, y);
	right = ret.first;
	return make_pair(this->Update(), ret.second);
}

Pair ret1, ret2;
Node *root;
long double l, r, mid;
int n, q, i, type, p, x, a[100005];

int main()
{
	null = new Node(0, 0, 0, null, null);
	root = null;
	scanf("%d %d", &n, &q);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		Node *now = new Node(a[i], i, 1, null, null);
		ret1 = root->Split(a[i], i);
		root = Merge(ret1.first, Merge(now, ret1.second));
	}
	
	for (i = 1; i <= q; i++)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d %d", &p, &x);
			ret1 = root->Split(a[p], p - 1);
			ret2 = ret1.second->Split(a[p], p);
			root = Merge(ret1.first, ret2.second);
			a[p] = x;
			Node *now = new Node(a[p], p, 1, null, null);
			ret1 = root->Split(a[p], p);
			root = Merge(ret1.first, Merge(now, ret1.second));
		}
		
		else
		{
			long long vv;
			scanf("%I64d", &vv);
			r = (long double)(vv + 2147483647LL);
			l = 0.0;
			for (int tt = 1; tt <= 75; tt++)
			{
				mid = (l + r) * 0.5;
				ret1 = root->Split(mid);
				long double now = (long double)ret1.first->size * mid - (long double)ret1.first->ans;
				if (now > vv - 1e-9)
					r = mid;
				else
					l = mid;
				root = Merge(ret1.first, ret1.second);
			}
			
			printf("%.10f\n", (double)l);
		}
	}
	
	return 0;
}