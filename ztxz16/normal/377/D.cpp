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
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

struct Node
{
	int l, r, v, tag;
	
	friend bool operator < (Node a, Node b)
	{
		return a.v < b.v;
	}
}a[100005];

multimap <int, int> s;
int Left[2000005], Right[2000005], Max[2000005], tag[2000005], sel[2000005];
int n, i, ansnow, selnow, now, Ans;

void Make(int l, int r, int i);
void Work(int l, int r, int i, int type, int val);
void down(int i);
void up(int i);

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %d %d", &a[i].l, &a[i].v, &a[i].r), a[i].tag = i;
	sort(a + 1, a + n + 1);
	Make(1, 300000, 1);
	for (i = 1; i <= n; i++)
	{
		if (s.begin() != s.end())
		{
			while (s.begin() != s.end() && s.begin()->first < a[i].v)
			{
				int now = s.begin()->second;
				Work(a[now].l, a[now].v, 1, 1, -1);
				s.erase(s.begin());
			}
		}
		
		s.insert(make_pair(a[i].r, i));
		Work(a[i].l, a[i].v, 1, 1, 1);
		ansnow = 0;
		Work(1, 300000, 1, 2, 0);
		if (ansnow > Ans)
			Ans = ansnow;
	}
	
	printf("%d\n", Ans);
	s.clear();
	Make(1, 300000, 1);
	for (i = 1; i <= n; i++)
	{
		if (s.begin() != s.end())
		{
			while (s.begin() != s.end() && s.begin()->first < a[i].v)
			{
				int now = s.begin()->second;
				Work(a[now].l, a[now].v, 1, 1, -1);
				s.erase(s.begin());
			}
		}
		
		s.insert(make_pair(a[i].r, i));
		Work(a[i].l, a[i].v, 1, 1, 1);
		ansnow = 0;
		Work(1, 300000, 1, 2, 0);
		if (ansnow == Ans)
		{
			int ll = selnow, rr = a[i].v;
			for (int i = 1; i <= n; i++)
			{
				if (a[i].l <= ll && a[i].r >= rr && a[i].v >= ll && a[i].v <= rr)
					printf("%d ", a[i].tag);
			}
			
			printf("\n");
			return 0;
		}
	}
	
	return 0;
}

void Make(int l, int r, int i)
{
	int mid = ((l + r) >> 1);
	Left[i] = l, Right[i] = r, Max[i] = tag[i] = 0, sel[i] = l;
	if (l == r)
		return;
	Make(l, mid, (i << 1));
	Make(mid + 1, r, ((i << 1) | 1));
}

void Work(int l, int r, int i, int type, int val)
{
	if (l > Right[i] || r < Left[i])
		return;
	if (l <= Left[i] && r >= Right[i])
	{
		if (type == 1)
			Max[i] += val, tag[i] += val;
		else if (Max[i] > ansnow)
			ansnow = Max[i], selnow = sel[i];
		return;
	}
	
	down(i);
	Work(l, r, (i << 1), type, val);
	Work(l, r, ((i << 1) | 1), type, val);
	up(i);
}

void down(int i)
{
	int lc = (i << 1), rc = (lc | 1);
	if (tag[i] != 0)
	{
		Max[lc] += tag[i], tag[lc] += tag[i];
		Max[rc] += tag[i], tag[rc] += tag[i];
		tag[i] = 0;
	}
}

void up(int i)
{
	int lc = (i << 1), rc = (lc | 1);
	if (Max[lc] > Max[rc])
		Max[i] = Max[lc], sel[i] = sel[lc];
	else
		Max[i] = Max[rc], sel[i] = sel[rc];
}