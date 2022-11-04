#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long
using namespace std;
struct ST
{
	int l, r;
	ST *ch[2];
	ll mxs, lz;
}p[maxn << 1], *root;
int stcnt = 0;
void upd(ST *a)
{
	a->mxs = max(a->ch[0]->mxs, a->ch[1]->mxs);
}
void pushlz(ST *a, ll lz)
{
	a->lz += lz, a->mxs += lz;
}
void pushdown(ST *a)
{
	if(!a->lz) return ;
	pushlz(a->ch[0], a->lz), 
	pushlz(a->ch[1], a->lz);
	a->lz = 0;
}
int nr = 1000002;
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r;
	a->lz = 0, a->mxs = r - nr;
	if(l == r) 
		return;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
}
void push(ST *a, int l, int r, int lz)
{
//	cout<<a->l<<" "<<a->r<<" "<<l<<" "<<r<<endl;
	if(a->l == l && a->r == r)
	{
		pushlz(a, lz);
		return;
	}
	int mid = (a->l + a->r) >> 1;
	pushdown(a);
	if(r <= mid) push(a->ch[0], l, r, lz);
	else if(l > mid) push(a->ch[1], l, r, lz);
	else push(a->ch[0], l, mid, lz), 
		push(a->ch[1], mid + 1, r, lz);
	upd(a);
}
ll q(ST *a, int l, int r)
{
	if(l > r) return 0;
	if(a->l == l && a->r == r) 
	{
	//	cout<<a->l<<" "<<a->r<<" "<<a->mxs<<" "<<a->lz<<endl;
		return a->mxs;
	}
	int mid = (a->l + a->r) >> 1;
	pushdown(a);
	if(r <= mid) return q(a->ch[0], l, r);
	else if(l > mid) return q(a->ch[1], l, r);
	else 
		return max(q(a->ch[0], l, mid), q(a->ch[1], mid + 1, r));
}
int t[maxn], d[maxn];
int main()
{
	int qs;
	scanf("%d", &qs);
	root = &p[stcnt++];
	bdtree(root, 1, nr);
	int ncnt = 0;
	for(int i = 1; i <= qs; i++)
	{
		char inp[3];
		scanf("%s", inp);
		if(inp[0] == '+')
			scanf("%d%d", &t[i], &d[i]), 
			push(root, 1, t[i], d[i]);
		else if(inp[0] == '-')
		{
			int k;
			scanf("%d", &k);
			push(root, 1, t[k], -d[k]);
		}
		else
		{
			int t;
			scanf("%d", &t);
			printf("%lld\n", max(0ll, 1 + q(root, 1, t) - q(root, t + 1, t + 1)));
		//	cout<<q(root, 1, t)<<endl;
		}
	}
	return 0;
}
/*
3
+ 2 2
? 3
*/