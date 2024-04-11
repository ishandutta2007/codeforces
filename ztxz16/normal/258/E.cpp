#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define NMAX 100005
#define MMAX 200005
#define segmax 400005

using namespace std;

struct Toperation
{
	int kind, left, right;
};

vector <Toperation> Op[NMAX];
vector <Toperation>::iterator it;

int Left[NMAX], Right[NMAX], tag[NMAX];
int e[MMAX], succ[MMAX], last[NMAX], sum;
int left[segmax], right[segmax], Sum[segmax], EntireTag[segmax];
int n, m, i, a, b, Ans, tot, LastAns[NMAX];

void dfs(int Now, int f);
void AddOperation(int a1, int b1, int a2, int b2);
void Make(int l, int r, int i);
void Add(int l, int r, int i);
void Del(int l, int r, int i);
inline void dis(int &i);
void Ask();

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	dfs(1, 0);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		AddOperation(Left[a], Right[a], Left[b], Right[b]);
	}
	
	Make(1, n, 1);
	for (i = 1; i <= n; i++)
	{
		for (it = Op[i].begin(); it != Op[i].end(); ++it)
		{
			if (it->kind == 2)
				continue;
			Add(it->left, it->right, 1);
		}
		
		Ans = 0, Ask();
		if (Ans > 0)
			Ans--;
		LastAns[tag[i]] = Ans;
		
		for (it = Op[i].begin(); it != Op[i].end(); ++it)
		{
			if (it->kind == 1)
				continue;
			Del(it->left, it->right, 1);
		}
	}
	
	for (i = 1; i <= n; i++)
		printf("%d ", LastAns[i]);
	printf("\n");
	return 0;
}

void dfs(int Now, int f)
{
	int x;
	Left[Now] = ++tot;
	tag[tot] = Now;
	for (x = last[Now]; x != 0; x = succ[x])
	{
		if (e[x] == f)
			continue;
		dfs(e[x], Now);
	}
	
	Right[Now] = tot;
	return;
}

void AddOperation(int a1, int b1, int a2, int b2)
{
	Toperation op1, op2;
	op1.kind = 1, op1.left = a1, op1.right = b1;
	op2.kind = 1, op2.left = a2, op2.right=  b2;
	Op[a1].push_back(op1), Op[a1].push_back(op2);
	Op[a2].push_back(op1), Op[a2].push_back(op2);
	op1.kind = op2.kind = 2;
	Op[b1].push_back(op1), Op[b1].push_back(op2);
	Op[b2].push_back(op1), Op[b2].push_back(op2);
	return;
}

void Make(int l, int r, int i)
{
	int mid = ((l + r) >> 1);
	left[i] = l, right[i] = r;
	if (l == r)
		return;
	Make(l, mid, (i << 1));
	Make(mid + 1, r, ((i << 1) | 1));
	return;
}

void Add(int l, int r, int i)
{
	if (l > right[i] || r < left[i])
		return;
	if (l <= left[i] && r >= right[i])
	{
		EntireTag[i]++;
		return;
	}
	
	Add(l, r, (i << 1));
	Add(l, r, ((i << 1) | 1));
	dis(i);
	return;
}

void Del(int l, int r, int i)
{
	int lc, rc;
	if (l > right[i] || r < left[i])
		return;
	if (l <= left[i] && r >= right[i] && EntireTag[i]  > 0)
	{
		EntireTag[i]--;
		return;
	}
	
	lc = (i << 1), rc = (lc | 1);
	if (EntireTag[i] > 0)
	{
		EntireTag[i]--;
		EntireTag[lc]++, EntireTag[rc]++;
	}
	
	Del(l, r, lc), Del(l, r, rc), dis(i);
	return;
}

inline void dis(int &i)
{
	int lc = (i << 1), rc = ((i << 1) | 1);
	Sum[i] = 0;
	if (EntireTag[lc] > 0)
		Sum[i] += (right[lc] - left[lc] + 1);
	else
		Sum[i] += Sum[lc];
	if (EntireTag[rc] > 0)
		Sum[i] += (right[rc] - left[rc] + 1);
	else
		Sum[i] += Sum[rc];
	return;
}

void Ask()
{
	if (EntireTag[1] > 0)
		Ans = n;
	else
		Ans = Sum[1];
	return;
}